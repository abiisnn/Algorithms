#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> num(n);
		map<int, int> buck;
		fore(i, 0, n) {
			cin >> num[i];
			buck[num[i]]++;
		}
		int mindif = 100000;
		sort(num.begin(), num.end());
		fore(i, 0, num.size()-1) {
			int dif = abs(num[i+1] - num[i]);
			if(dif < mindif) mindif = dif;
		}
		cout << mindif << endl;
	}
}