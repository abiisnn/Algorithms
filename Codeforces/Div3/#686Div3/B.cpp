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
#define MAX 300000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	int n; cin >> n;

	map<int, int> bucket;
	vector<int> v(n);
	fore(i, 0, n) {
		cin >> v[i];
		bucket[v[i]]++;
	}
	int best = MAX, index = -1;
	fore(i, 0, n) {
		int cont = bucket[v[i]];
		if(cont == 1) {
			if(v[i] < best) {
				best = v[i];
				index = i+1;
			}
		}
	}
	cout << index << endl;
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}