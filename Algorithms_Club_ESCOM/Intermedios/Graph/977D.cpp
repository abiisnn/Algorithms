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
vector<bool> canPass(100 * 2 + 1, false);
map<lli, int> mapping;
vector<lli> values(100 * 2 + 1, 0);

int bfs(vector<vector<int>> &adj, vector<int> &path, int u, bool flag) {
	vector<bool> visited(200, false);
	queue<int> bfs;
	bfs.push(u);
	int last = 0;
	while(!bfs.empty()) {
		int u = bfs.front();
		last = u;
		bfs.pop();
		if(flag) path.push_back(u);
		visited[u] = true;
		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if(visited[v] or !canPass[v]) continue;
			visited[v] = true;
			bfs.push(v);
		}
	}
	return last;
}
bool isValid(vector<int> &v) {
	bool valid = true;
	for(int i = 0; i < v.size() -1; i++) {
		lli a = values[v[i]], b = values[v[i+1]];
		if(a * 2ll == b) continue;
		if(a % 3ll == 0 && a/3ll == b) continue;
		valid = false;
		break;
	}
	return valid;
}
int getNode(lli number, int &node) {
	int u = mapping.count(number);
	if(!u) {
		mapping[number] = node;
		node++;
	}
	u = mapping[number];
	values[u] = number;
	return u;
}
int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> numbers(100 * 2 + 1);
	vector<vector<int>> adj(100 * 2+1, vector<int>());
	int node = 1;
	for(int i = 0; i < n; i++) {
		cin >> numbers[i];
		int u = getNode(numbers[i], node);
		canPass[u] = true;
		
		int v = getNode(numbers[i] * 2ll, node);
		adj[u].push_back(v);
		adj[v].push_back(u);

		if(numbers[i] % 3ll == 0) {
			v = getNode(numbers[i] / 3ll, node);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	vector<int> path;
	int last = bfs(adj, path, mapping[numbers[0]], false);
	last = bfs(adj, path, last, true);

	if(!isValid(path)) reverse(all(path));
	for(int i = 0; i < path.size(); i++) {
		cout << values[path[i]] << " ";
	} cout << endl;
}	