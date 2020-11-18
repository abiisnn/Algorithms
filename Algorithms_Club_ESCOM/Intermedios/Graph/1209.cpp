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
#define N 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<bool> visited(N, false);

int bfs(vector<vector<int>> &adj, int u) {
	if(visited[u]) return 0;
	if(adj[u].size() == 0) return 0;
	queue<int> q; q.push(u);
	int total = 0;
	while(!q.empty()) {
		int current = q.front(); q.pop();
		visited[current] = true;
		total++;
		for(auto &v: adj[current]) {
			if(visited[v]) continue;
			visited[v] = true;
			q.push(v);
		}
	}
	return total - 1;
}

int main() {
	optimizar_io
	int n, k; cin >> n >> k;
	vector<vector<int>> adj(n+1, vector<int>(0));

	fore(i, 0, k) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int total = 0;
	for(int i = 1; i < (int)adj.size(); i++) total += bfs(adj, i);
	cout << k - total << endl;
}