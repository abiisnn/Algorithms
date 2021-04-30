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
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	lli l, r; cin >> l >> r;
	int limit; cin >> limit;
	for(lli i = l; i <= r; i++) {
		for(int j = 0; j <= limit; j++) {
			ld res = i % j;
			ld second = j / 2.0;
			cout << "con: " << j << "res: " << res << " sec: " << second <<endl; 
		}
	}
}

int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}