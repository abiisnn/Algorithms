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
vector<int> state(MAX), last(MAX);
vector<vector<bool>> dis(MAX, vector<bool>(MAX, true));
void clear() {
	for(int i = 0; i < MAX; i++) state[i] = 0;
}
bool edgesOfCycle(vector<vector<int>> &adj, vector<pair<int, int>> &cycle, int u) {
	state[u] = 1;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(state[v] == 2) continue;
		if(state[v] == 1) {
			// Find cycle
			int start = v, current = u;
			cycle.push_back(make_pair(u, v));
			while(start != current) {
				cycle.push_back(make_pair(last[current], current));
				current = last[current]; 
			}
			return true;
		}
		last[v] = u;
		if(edgesOfCycle(adj, cycle, v)) return true;
	}
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
	vector<pair<int, int>> cycle;

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	bool ans = false;
	bool flagCycle = false;
	for(int i = 1; i <= n; i++) {
		if(edgesOfCycle(adj, cycle, i)) {
			flagCycle = true;
			break;
		}
	}

	if(flagCycle) {
		for(int i = 0; i < cycle.size(); i++) {
			dis[cycle[i].first][cycle[i].second] = false;
			if(!checkCycle(adj)) {
				ans = true;
				break;
			}
			dis[cycle[i].first][cycle[i].second] = true;
		} 
	}
	if(ans or !flagCycle) cout << "YES";
	else cout << "NO";
	cout << endl;
}	