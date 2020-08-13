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

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int badOdd = 0, badEven = 0;
	fore(i, 0, n) {
		cin >> v[i];
		if((i & 1) && (v[i] & 1)) continue;
		if(!(i & 1) && !(v[i] & 1)) continue;
		if((i&1) && !(v[i] & 1)) badOdd++;
		if(!(i&1) && (v[i] & 1)) badEven++;
	}
	if(badEven == badOdd) {
		cout << badOdd << endl;
	} else cout << -1 << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) {
		solve();
	}
}