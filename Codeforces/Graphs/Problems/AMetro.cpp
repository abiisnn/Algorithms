// https://codeforces.com/problemset/problem/1055/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 10000005
typedef long long int lli;
void readData(int &nNodes, vector<vector<int>> &adj) {
	// GO
	int neigh, last = 0;
	for(int i = 1; i < nNodes; i++) {
		cin >> neigh;
		if(last && neigh) adj[last].pb(i); 
		if(neigh) last = i;
	}
	vector<int> aux(nNodes, 0);
	for(int i = nNodes - 1; i > 0; i--) cin >> aux[i];
	
	// BACK
	last = 0; nNodes--;
	for(int i = nNodes, j = 1; i > 0; i--, j++) {
		if(last && aux[j]) adj[last].pb(i);
		if(aux[j]) last = i;
	}
}
void clearVisited(vector<bool> &visited) {
	for(int i = 0; i < visited.size(); i++) visited[i] = false;
}

bool search(int from, int to, vector<vector<int>> &adj, vector<bool> &visited) {
	if(from == to) return true;
	if(visited[from]) return false;
	if(!visited[from]) visited[from] = true;

	for(int i = 0; i < adj[from].size(); i++) {
		bool ans = search(adj[from][i], to, adj, visited); 
		if(ans) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int nNodes, neigh, to;
	cin >> nNodes >> to;
	nNodes++; //Beggining with 1

	vector<vector<int>> adj(nNodes);
	vector<bool> visited(nNodes, false);
	for(int i = 0; i < nNodes; i++) {
		vector<int> aux;
		adj[i] = aux;
	}
	
	readData(nNodes, adj);

	bool flag = false;
	if(search(1, to, adj, visited)) flag = true;

	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}