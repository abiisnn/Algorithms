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
#define MAX 250005
#define C 3
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<lli> fac(MAX);
lli modularInverse(lli a, lli m) {
	lli r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
	while(r1){
		si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
		ri = r0 % r1, r0 = r1, r1 = ri;
	}
	if(r0 < 0) s0 *= -1;
	if(s0 < 0) s0 += m;
	return s0;
}

int main() {
	optimizar_io
	int n; 
	lli m; cin >> n >> m;
	fac[0] = 1ll;
	for(lli i = 1ll; i < MAX; i++) {
		fac[i] = (fac[i-1] * i) % m;
	}
	cout << "fac n" << fac[n] << " " << fac[n-1] << endl;
	lli ans = (fac[n] * fac[n-1]) % m;
	ans += 2ll;
	ans %= m;
	cout << ans << endl;
}