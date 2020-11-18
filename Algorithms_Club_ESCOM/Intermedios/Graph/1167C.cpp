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
#define MAX 500005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<bool> visited(MAX, false);
vector<int> belog(MAX, 0);

void dfs(vector<vector<int>> &adj, int u, int current) {
	if(visited[u]) return;
	visited[u] = true;
	belog[u] = current;
	for(int i = 0; i < adj[u].size(); i++) {
		dfs(adj, adj[u][i], current);
	}
}
int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n+1, vector<int>(0));
	for(int i = 0; i < m; i++) {
		int k; cin >> k;
		if(!k) continue;
		int u, v; cin >> u; 
		for(int i = 1; i < k; i++) {
			cin >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			u = v;
		}
	}

	int current = 1;
	for(int i = 1; i <= n; i++) {
		dfs(adj, i, current);
		current++;
	}
	vector<int> bucket(MAX);
	for(int i = 0; i < MAX; i++) bucket[belog[i]]++;
	for(int i = 1; i <= n; i++) cout << bucket[belog[i]] << " ";
	cout << endl;
}