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

int main() {
	optimizar_io
	int n, a, b;
	lli s;
	cin >> s >> n;
	vector<pair<int, int>> dragons;
	fore(i, 0, n) {
		cin >> a >> b;
		dragons.pb(mk(a, b));
	}
	sort(dragons.begin(), dragons.end());

	bool ans = true;
	fore(i, 0, n) {
		if(s > dragons[i].fi) s += dragons[i].se;
		else {
			ans = false;
			break;
		}
	}
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}