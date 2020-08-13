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
#define MOD 1000000007
#define INF 500000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n), aux;
	fore(i, 0, n) cin >> v[i];
	aux = v;
	sort(all(v));
	if(aux == v) cout << "Yes" << endl;
	else cout << "No" << endl;
}
int main() {
	int q; cin >> q;
	while(q--) {
		solve();
	}
}