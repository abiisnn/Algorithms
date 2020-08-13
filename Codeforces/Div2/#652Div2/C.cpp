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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	int n, k; cin >> n >> k;
	vector<lli> a(n);
	vector<int> w(k);
	fore(i, 0, n) cin >> a[i];
	fore(i, 0, k) cin >> w[i];
	sort(all(a)); sort(all(w));
	reverse(all(w));
	lli ans = 0;
	for(int i = 0, j = 0; i < n-k; i += w[j]-1, j++) ans += a[i];
	
	for(int i = n-k, j = 0; i < n; i++, j++) {
		ans += a[i];
		if(!(w[j]-1)) ans += a[i];
	}
	cout << ans << endl;
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}