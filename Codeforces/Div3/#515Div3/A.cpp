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

// Brute force solution
void solve() {
	lli L, v, l, r;
	cin >> L >> v >> l >> r;
	lli canSee = 0;
	for(lli i = 1ll; i <= L; i++) {
		if(i >= l && i <= r) continue;
		if(!(i % v)) { // i % v == 0
			canSee++;
		}
	}
	cout << canSee << endl;
}
/*
// Improve of brute force solution
void solve() {
	lli L, v, l, r;
	cin >> L >> v >> l >> r;
	lli canSee = 0;
	for(lli i = 1; i <= L; i++) {
		if(i != 0) continue;
		if(i >= l && i <= r) continue;
		if(!(i % r)) { // i % r == 0
			canSee++;
		}
	}
}
*/
void solve() {
	lli L, v, l, r;
	cin >> L >> v >> l >> r;
	lli total = L / v;
	total -= r / v;
	total += (l-1) / v;
	cout << total << endl;
}

int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}