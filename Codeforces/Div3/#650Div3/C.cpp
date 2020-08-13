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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> pos;
	fore(i, 0, s.size()) {
		if(s[i] == '1') pos.pb(i);
	}
	int last = 0, dis, ans = 0;
	if(pos.size() > 0) {
		dis = pos[0] - 0;
		ans += (dis / (k+1));
		last = pos[0];
		fore(i, 1, pos.size()) {
			dis = pos[i] - last-1 - k;
			last = pos[i];
			if(dis <= 0) continue;
			ans += (dis / (k+1));
		}	
		dis = s.size() - pos[pos.size() - 1] - 1-k;
		if(dis > 0) {
			ans += (dis / (k+1));
			int res = dis % (k+1);
			if(res) ans++;
		}
	} else {
		ans = s.size() / (k+1);
		int res = s.size() % (k+1);
		if(res) ans++;  
	}
	cout << ans << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) {
		solve();
	}
}