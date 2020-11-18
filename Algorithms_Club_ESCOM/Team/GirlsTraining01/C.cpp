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
#define MAX_INT 1000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void swap(vector<vector<int>> &adj, int x, int y) {
	vector<vector<int>> temp = adj;
	for(int i = 0; i < adj.size(); i++) {
		for(int j = 0; j < adj[i].size(); i++) {
			if(adj[i][j] == x) {
				temp[i][j] = y;
			} else if(adj[i][j] == y) {
				temp[i][j] = x;
			}
		}
	}
	vector<int> aux = temp[x];
	temp[x] = temp[y];
	temp[y] = aux;
	adj = temp;
}
bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int from, int to) {
	if(visited[from]) return false;
	if(from == to) return true;
	visited[from] = true;
	for(int i = 0; i < adj[from].size(); i++) {
		if(dfs(adj, visited, adj[from][i], to)) {
			return true;
		}
	}
	return false;
}
int findBest(vector<vector<int>> &adj, vector<int> &age, int x) {
	int best = MAX_INT;
	for(int i = 1; i < adj.size(); i++) {
		vector<bool> visited(adj.size(), false);
		if(i != x && dfs(adj, visited, i, x)) {
			best = min(best, age[i]);
		}
	}
	return best;
}
int main() {
	optimizar_io
	int n, m, q; cin >> n >> m >> q;
	vector<vector<int>> adj(n+1, vector<int>(0));
	vector<int> info(n+1);
	// employee age
	for(int i = 1; i <= n; i++) cin >> info[i];

	int x, y;
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
	}
	char inst;
	for(int i = 0; i < q; i++) {
		cin >> inst;
		if(inst == 'T') {
			cin >> x >> y;
			swap(adj, x, y);
		} else {
			cin >> x;
			int age = findBest(adj, info, x);
			if(age != MAX_INT) cout << age << endl;
			else cout << "*" << endl;
		}
	}
}