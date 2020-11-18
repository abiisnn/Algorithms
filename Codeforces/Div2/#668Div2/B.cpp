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
	int sz; cin >> sz;
	vector<pair<lli, int>> pos, neg;
	for(int i = 0; i < sz; i++) {
		lli num; cin >> num;
		if(num >= 0) pos.pb(mk(num, i));
		else neg.pb(mk(num, i));
	}
	int p = 0, n = 0;
	while(p < pos.size() && n < neg.size()) {
		if(neg[n].fi >= 0) n++; 
		else if(pos[p].se < neg[n].se) {
			if(pos[p].fi > 0) {
				lli dif = min(pos[p].fi, abs(neg[n].fi));
				pos[p].fi -= dif;
				neg[n].fi += dif;
			} else {
				p++;
			}
		} else {
			n++;
		}
	}
	lli total = 0;
	for(int i = 0; i < pos.size(); i++) {
		total += pos[i].fi;
	}
	cout << total << endl;
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}