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
#define MAX 10005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<int> parent(MAX+1);
vector<int> level(MAX+1);
vector<vector<int>>adj(MAX+1, vector<int>(0));

int bfs(int u) {
	int last = 0;
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		fore(i, 0, adj[v].size()) {
			if(adj[v][i] != parent[v]) {
				q.push(adj[v][i]);
				parent[adj[v][i]] = v;
				level[adj[v][i]] = level[parent[adj[v][i]]] + 1;
				last = adj[v][i];
			}
		}
	}
	return last;
}
void clear() {
	fore(i, 0, level.size()) level[i] = 0;
	fore(i, 0, parent.size()) parent[i] = 0;
}
int main() {
	optimizar_io
	int n; cin >> n;
	int u, v;
	fore(i, 0, n) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	level[1] = 0;
	int last = bfs(1);
	clear();
	last = bfs(last);	
	cout << level[last] << endl;
}