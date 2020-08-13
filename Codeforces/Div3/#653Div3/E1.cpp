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
#define MAX 10000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, k, t; cin >> n >> k;
	lli A, B;
	vector<lli> zz, a, b;
	fore(i, 0, n) {
		cin >> t >> A >> B;
		if(A && B) zz.pb(t);
		else if(A) a.pb(t);
		else if(B) b.pb(t);
	}
	sort(all(zz)); sort(all(a)); sort(all(b));
	int izz = 0, iab = 0, sa = a.size(), sb = b.size();
	lli ans = 0;
	bool sol = true;
	while(1) {
		if(!k) break;
		lli opzz = MAX, opab = MAX;
		if(izz < zz.size()) opzz = zz[izz];
		if(iab < std:: min(sa, sb)) opab = a[iab] + b[iab];
		if(opzz == MAX && opab == MAX) {
			sol = false;
			break;
		}
		if(opzz < opab) {
			ans += opzz;
			izz++;
		} else {
			ans += opab;
			iab++;
		}
		k--;
	}
	if(sol) cout << ans << endl;
	else cout << -1 << endl;
}