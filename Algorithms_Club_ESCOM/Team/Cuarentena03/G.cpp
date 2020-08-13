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
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<int> parent(MAX+1);
vector<int> level(MAX+1);
vector<int> visited(MAX+1, false);
void clear() {
	fore(i, 0, level.size()) level[i] = 0;
	fore(i, 0, parent.size()) parent[i] = 0;
	fore(i, 0, visited.size()) visited[i] = false;
}
bool dfs(vector<vector<int>> &adj, int from, int to, vector<int> &path) {
	if(from == to) return true;
	if(visited[from]) return false;
	visited[from] = true;
	bool ans = false;
	for(int i = 0; i < adj[from].size(); i++) {
		if(dfs(adj, adj[from][i], to, path)) {
			path.pb(adj[from][i]);
			ans = true;
			break;
		}
	}
	return ans;
}
int bfs(vector<vector<int>>&adj, int u, int a, int b) {
	int last = 0;
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		fore(i, 0, adj[v].size()) {
			if(adj[v][i] != parent[v] && adj[v][i] != a && adj[v][i] != b) {
				q.push(adj[v][i]);
				parent[adj[v][i]] = v;
				level[adj[v][i]] = level[parent[adj[v][i]]] + 1;
				last = adj[v][i];
			}
		}
	}
	return last;
}

int main() {
	optimizar_io
	int n; cin >> n;
	int u, v, ter = 0, best = 0;
	vector<vector<int>>adj(MAX+1, vector<int>(0));
	vector<vector<int>>adj2(MAX+1, vector<int>(0));
	fore(i, 0, n-1) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cin >> n;
	fore(i, 0, n-1) {
		cin >> u >> v;
		adj2[u].pb(v);
		adj2[v].pb(u);
	}
	// Primero
	level[1] = 0;
	int beg = bfs(adj, 1, -1, -1);
	clear();
	int end = bfs(adj, beg, -1, -1);
	int total = level[end];
	clear();
	level[1] = 0;
	beg = bfs(adj2, 1, -1, -1);
	clear();
	end = bfs(adj2, beg, -1, -1);
	int total2 = level[end] / 2;
	if(total > total2) {
		cout << "GGEZ" << endl;
	} else cout << "FF" << endl;
}