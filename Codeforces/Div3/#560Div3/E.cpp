#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MOD 998244353ll
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> a(n), b(n);
	fore(i, 0, n) cin >> a[i];
	fore(i, 0, n) cin >> b[i];
	fore(i, 0, n) {
		lli times = (i + 1ll) * (n - i) * 1ll;
		a[i] = (a[i] * times);
	}
	sort(all(a)); sort(all(b));
	reverse(all(b));
	
	lli ans = 0;
	for(int i = 0; i < n; i++) {
		a[i] %= MOD;
		b[i] %= MOD;
		lli mul = (a[i] * b[i]);
		mul %= MOD;
		ans = (ans + mul);
		ans %= MOD;
	}
	cout << ans << endl;
}