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
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<bool> visited(MAX, false);
void bfs(vector<vector<int>> &adj, vector<vector<int>> &ans, int index) {
	queue<int> nodes;
	nodes.push(index);
	while(!nodes.empty()) {
		int v = nodes.front();
		nodes.pop();
		visited[v] = true;
		fore(i, 0, adj[v].size()) {
			int u = adj[v][i];
			if(!visited[u]) {
				ans[v].pb(u);
				nodes.push(u);
				visited[u] = true;
			}
		}
	}
}
int main() {
	optimizar_io
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n+1, vector<int>(0)), ans(n+1, vector<int>(0));
	int u, v;
	fore(i, 0, m) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int index = 0, greater = 0;
	fore(i, 0, adj.size()) {
		if(adj[i].size() > greater) greater = adj[i].size(), index = i;
	}
	bfs(adj, ans, index);

	fore(i, 1, ans.size()) {
		fore(j, 0, ans[i].size()) {
			cout << i << " " << ans[i][j] << endl; 
		}
	}
}