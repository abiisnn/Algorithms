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
#define MAX 101
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n;
	lli d, a, b, l, h; cin >> n >> d;
	cin >> a >> b;
	vector<pair<lli, int>> p(n, pair<lli, int>(0, 0));
	fore(i, 0, n) {
		cin >> l >> h;
		p[i].fi = (l * a) + (h * b);
		p[i].se = i+1;
	}

	sort(all(p));
	lli aux = 0;
	vector<int> ans;
	fore(i, 0, n) {
		if(aux + p[i].fi <= d) {
			aux += p[i].fi;
			ans.pb(p[i].se);
		}
		else break;
	}
	cout << ans.size() << endl;
	fore(i, 0, ans.size()) cout << ans[i] << " ";
	cout << endl;
}