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
#define MAX 505
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
/*
	0 -> not processed
	1 -> processing
	2 -> processed
*/
vector<int> state(MAX, 0);
vector<vector<bool>> dis(MAX, vector<bool>(MAX, true));
vector<int> path;
void clear() {
	for(int i = 0; i < MAX; i++) state[i] = 0;
}
bool disconnect(vector<vector<int>> &adj, int u) {
	if(state[u] == 2) return false;
	state[u] = 1;
	bool cycle = false;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(state[v] == 1) {
			path.push_back(v);
			return true;
		}
		if(disconnect(adj, v)) {
			path.push_back(v);
			return true;	
		}
	}
	state[u] = 2;
	return false;
}
bool existCycle(vector<vector<int>> &adj, int u) {
	if(state[u] == 2) return false;
	state[u] = 1;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(dis[u][v] && state[v] == 1) return true;
		if(dis[u][v] && existCycle(adj, v)) return true;
	}
	state[u] = 2;
	return false;
}
bool checkCycle(vector<vector<int>> &adj) {
	clear();
	for(int i = 1; i < adj.size(); i++) {
		bool aux = existCycle(adj, i);
		if(aux) return true;
	}
	return false;
}

int main() {
	optimizar_io
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n+1, vector<int>(0));

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	bool ans = false;
	bool cycle = false;
	for(int i = 1; i <= n; i++) {
		if(disconnect(adj, i)) {
			cycle = true;
			break;
		}
	}

	if(cycle) {
		reverse(all(path));
		int last = path[0];
		fore(i, 1, path.size()) {
			dis[last][path[i]] = false;
			if(!checkCycle(adj)) {
				ans = true;
				break;
			}
			dis[last][path[i]] = true;
			last = path[i];
		} 
		dis[last][path[0]] = false;
		if(!ans && !checkCycle(adj)) ans = true;
	}
	if(ans or !cycle) cout << "YES";
	else cout << "NO";
	cout << endl;
}	