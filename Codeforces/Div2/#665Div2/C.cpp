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
	int n; cin >> n;
	vector<lli> v(n), sorted;
	lli mini = MAX;
	fore(i, 0, n) {
		cin >> v[i];
		if(v[i] < mini) mini = v[i];
	}
	sorted = v;
	sort(all(sorted));
	bool ans = true;
	fore(i, 0, n) {
		if(v[i] != sorted[i] && (v[i] % mini) != 0) {
			ans = false;
			break;
		}
	}
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;

	while(t--) solve();
}