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

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	int odds = 0, even = 0;
	fore(i, 0, n) {
		cin >> v[i];
		if(v[i] & 1) odds++;
		else even++;
	}
	if(odds) {
		// Use max num of odds
		int maxNumOdds;
		if(odds >= x) {
			if(x & 1) maxNumOdds = x;
			else maxNumOdds = x - 1;
		} else {
			if(odds & 1) maxNumOdds = odds;
			else maxNumOdds = odds-1;
		}
		int need = x - maxNumOdds;
		if(need <= even) {
			cout << "Yes" << endl;
		} else cout << "No" << endl;
	} else cout << "No" << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) {
		solve();
	}
}