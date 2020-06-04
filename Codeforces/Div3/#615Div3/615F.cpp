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
int main() {
	optimizar_io
	int n; cin >> n;
	int u, v, ter = 0, best = 0;
	fore(i, 0, n-1) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	level[1] = 0;
	int beg = bfs(1, -1, -1);
	clear();
	int end = bfs(beg, -1, -1);
	int total = level[end];
	if(total != n-1) {
		vector<int> path;
		if(dfs(beg, end, path)) {
			path.pb(beg);
			clear();
			fore(i, 1, path.size()-1) {
				int last = bfs(path[i], path[i-1], path[i+1]);
				if(level[last] > best) {
					best = level[last];
					ter = last;
				}
			}
		}
		total += best;
	} else {
		fore(i, 1, n+1) {
			if(i != beg && i != end) {
				ter = i;
				break;
			}
		}
	}
	cout << total << endl;
	cout << beg << " " << end << " "<< ter << endl;
}