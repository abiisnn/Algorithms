#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n;
	int matrix[4][4];
	vector<int> row(4);
	fore(i, 0, 4) {
		int sumRow = 0;
		fore(j, 0, 4) {
			cin >> matrix[i][j];
			sumRow += matrix[i][j];
		}
		row[i] = sumRow;
	}
	cin >> n;
	string plato;
	map<string, int> bucket;

	while(n--) {
		cin >> plato;
		bucket[plato]++;
	}

	int total = 0;
	for(char i = 'A'; i <= 'D'; i++) {
		int freq = 10000;
		for(char j = '1'; j <= '4'; j++) {
			string key(1, i);
			key.push_back(j);
			freq = min(freq, bucket[key]);
		}
		for(char j = '1'; j <= '4'; j++) {
			string key(1, i);
			key.push_back(j);
			bucket[key] -= freq;
		}
		total = total + (row[i - 'A'] * freq) - (10 * freq);
		for(char j = '1'; j <= '4'; j++) {
			string key(1, i);
			key.push_back(j);
			if(bucket[key]) {
				total += (matrix[i - 'A'][j -'0' - 1] * bucket[key]);
			}
		}
	}
	cout << total << endl;
}