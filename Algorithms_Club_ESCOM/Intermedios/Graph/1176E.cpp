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

void printAns(vector<int> &v) {
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}
void solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> adj(n+1, vector<int>(0));
	vector<bool> visited(n+1, false);

	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> odd, even;
	queue<pair<int, int>> bfs;
	bfs.push(mk(1, 0));

	while(!bfs.empty()) {
		pair<int, int> u = bfs.front();
		bfs.pop();

		visited[u.first] = true;
		if(u.second & 1) odd.pb(u.first);
		else even.pb(u.first);
		
		for(int i = 0; i < adj[u.first].size(); i++) {
			int v = adj[u.first][i];
			if(!visited[v]) {
				bfs.push(mk(v, u.second + 1));
				visited[v] = true;
			}
		}
	}

	if(odd.size() <= (n / 2)) printAns(odd);
	else printAns(even);
}


int main() {
	optimizar_io
	int t; cin >> t;

	while(t--) solve();
}