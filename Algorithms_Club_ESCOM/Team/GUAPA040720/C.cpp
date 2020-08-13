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
#define MOD 999999929
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<lli> ocho(MAX);

void solve() {
	lli k; cin >> k;
	lli ans = 0;
	if(k == 1ll) {
		ans = 10ll % MOD;
		cout << ans << endl;
		return;
	}
	ans = 10ll % MOD;
	ans = (ans * 9ll) % MOD;
	ans = (ans * ocho[k-2]) % MOD;
	cout << ans << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	ocho[0] = 1ll;
	ocho[1] = 8ll;
	for(int i = 2; i < MAX; i++) ocho[i] = (ocho[i-1] * 8ll) % MOD;
	
	while(t--) {
		solve();
	}
}