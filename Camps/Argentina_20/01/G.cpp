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
#define MAX 100005
#define C 3
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<int> parent(MAX+1);
vector<int> level(MAX+1);
vector<int> visited(MAX+1, false);
vector<vector<int>>adj(MAX+1, vector<int>(0));
 
void clear() {
	fore(i, 0, level.size()) level[i] = 0;
	fore(i, 0, parent.size()) parent[i] = 0;
	fore(i, 0, visited.size()) visited[i] = false;
}
bool dfs(int from, int to, vector<int> &path) {
	if(from == to) return true;
	if(visited[from]) return false;
	visited[from] = true;
	bool ans = false;
	for(int i = 0; i < adj[from].size(); i++) {
		if(dfs(adj[from][i], to, path)) {
			path.pb(adj[from][i]);
			ans = true;
			break;
		}
	}
	return ans;
}
int bfs(int u, int a, int b) {
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
bool check(int u, lli actual, lli k) {
	if(visited[u]) return true;
	visited[u] = true;
	if(actual == 0 && adj[u].size() < 3) return false;
	if(actual <= k-1 && actual != 0 && adj[u].size() < 4) return false;
	if(actual == k && adj[u].size() > 1) return false;
	lli newAct = actual + 1;
	for(int i = 0; i < adj[u].size(); i++) {
		if(!check(adj[u][i], newAct, k)) return false;
	}
	return true;
}
int main() {
	optimizar_io
	lli k;z
	int n, u, v;
	cin >> n >> k;
	fore(i, 0, n-1) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	level[1] = 0;
	int beg = bfs(1, -1, -1);
	clear();
	int end = bfs(beg, -1, -1);
	vector<int> path;
	bool flag = true;
	if(dfs(beg, end, path)) {
		path.pb(beg);
		int center = path[path.size() / 2];
		clear();
		if(!check(center, 0, k)) flag = false;
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}