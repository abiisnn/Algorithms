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
#define MAX 5005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<int> last(MAX), discovery(MAX), euler; 
vector<lli> weight_subtree(MAX), weigth(MAX);
vector<vector<bool>> vis(MAX, vector<bool>(MAX, false));
vector<vector<int>> adj(MAX, vector<int>(0));

lli mem[MAX][MAX];
lli LINF = lli(1000000000) * 5005ll * -1ll;
int t = 0, n;

void tour(int root, int parent) {
	discovery[root] = t;
	t++;
	euler.pb(root);
	fore(i, 0, adj[root].size()) {
		if(parent != adj[root][i]) 
			tour(adj[root][i], root);
	}
	last[root] = t - 1;
}
void build() {
	vector<lli> acum(n);
	acum[0] = weigth[euler[0]];
	fore(i, 1, n) acum[i] = acum[i-1] + weigth[euler[i]];
	fore(i, 0, n) {
		int start = discovery[i] - 1;
		if(start < 0) weight_subtree[i] = acum[last[i]];
		else weight_subtree[i] = acum[last[i]] - acum[start];
	}
}
lli max(lli a, lli b) {
	if(a > b) return a;
	return b;
}
lli dp(int i, int k) {
	if(!k) return 0;
	if(i >= n) return LINF;
	if(vis[i][k]) return mem[i][k];
	vis[i][k] = true;
	lli notake = dp(i+1, k), take = dp(last[euler[i]]+1, k-1), ans = LINF;
	if(take != LINF && notake != LINF) ans = max(notake, take + weight_subtree[euler[i]]);
	else if(take != LINF) ans = take + weight_subtree[euler[i]];
	else if(notake != LINF) ans = notake;
	return mem[i][k] = ans;
}
int main() {
	optimizar_io
	int k, u, v; cin >> n >> k;
	fore(i, 0, n) {
		cin >> weigth[i];
	}
	last[n] = n;
	fore(i, 0, n-1) {
		cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	tour(0, -1);
	build(); // Get weight of subtree
	
	lli ans = dp(0, k);
	if(ans != LINF) cout << ans << endl;
	else cout << "Impossible" << endl;
}