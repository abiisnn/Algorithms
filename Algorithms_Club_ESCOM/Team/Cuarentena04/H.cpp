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
bool comp(pair<lli, int> &a, pair<lli, int> &b) {
	if(b.fi == a.fi) return a.se < b.se;
	return a.fi < b.fi;
}
int max(int a, int b) {if(a > b) return a; return b;}
int min(int a, int b) {if(a < b) return a; return b;}

void solve(vector<lli> &D) {
	lli x, y;
	cin >> x >> y;
	lli dif = abs(y - x);
	vector<pair<lli, int>> posans;
	vector<lli>::iterator low = std::lower_bound(D.begin(), D.end(), dif); // pos = 1
	int index = (low - D.begin());
	int inicio = max(index-50, 0), fin = min(index+50, D.size());
	fore(i, inicio, fin) {
		if(y - D[i] > 0) {
			lli newDif = abs(y - D[i] - x);
			if(newDif < dif) posans.pb(mk(newDif, i+1));
		}
	}
	sort(posans.begin(), posans.end(), comp);
	if(posans.size()) {
		if(posans[0].fi < dif) {
			cout << posans[0].se << endl;
		} else cout << 0 << endl;
	} else cout << 0 << endl;
}
int main() {
	optimizar_io
	int n, t; cin >> n;
	vector<lli> D(n), R;

	fore(i, 0, n) cin >> D[i];
	cin >> t;

	lli x, y;
	while(t--) {
		solve(D);
	}
}