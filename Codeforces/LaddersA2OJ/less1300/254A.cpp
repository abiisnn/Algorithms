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
	optimizar_io
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, a;
	cin >> n;
	map<int, vector<int>> bucket;
	fore(i, 0, 2*n) {
		cin >> a;
		bucket[a].pb(i+1);
	}

	bool ans = true;
	for(auto &i: bucket) {
		if(i.se.size() % 2 != 0) {
			ans = false;
			break;
		}
	}
	if(ans) {
		for(auto &i: bucket) {
			for(int j = 0; j < i.se.size(); j+=2) {
				cout << i.se[j] << " " << i.se[j+1] << endl;
			}
		}
	} 
	else cout << -1 << endl;
}