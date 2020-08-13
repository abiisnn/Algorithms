#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MOD 11092019
#define MAX 100000
typedef long long int lli;

int bfs(int from, int to, vector<bool> &visited, vector<vector<int>> &adj) {
	queue<pair<int, int>> q;
	int nivel = 0;
	q.push({from, nivel});
	while(!q.empty()) {
		pair<int, int> g = q.front();
		q.pop();	
		if(visited[g.first]) continue;
		else {
			visited[g.first] = true;
			if(g.first == to) return g.second;
			for(int i = 0; i < adj[g.first].size(); i++) {
				q.push({adj[g.first][i], g.second + 1});
			}
		}
	}
	return -1;
}

int main() {
	optimizar_io
	int n, m, u, v;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>(0));
	fore(i, 0, m) {
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<bool> visited(n, false);
	int prof = bfs(0, n-1, visited, adj);
	cout << prof - 1 << endl;
}