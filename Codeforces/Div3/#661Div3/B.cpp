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
#define MAX 1000000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli min(lli a, lli b) {
	if(a < b) return a;
	return b;
}
void solve() {
	int n; cin >> n;
	vector<lli> a(n), b(n);
	lli minA = MAX, minB = MAX; 
	fore(i, 0, n) {
		cin >> a[i];
		if(a[i] < minA) minA = a[i];
	}
	fore(i, 0, n) {
		cin >> b[i];
		if(b[i] < minB) minB = b[i];
	}
	lli ans = 0;
	fore(i, 0, n) {
		lli difA = a[i] - minA;
		lli difB = b[i] - minB;
		lli aux = min(difB, difA);
		ans += aux; // both
		ans += (difA - aux);
		ans += (difB - aux);
	}
	cout << ans << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}