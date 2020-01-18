// https://codeforces.com/problemset/problem/500/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 10000005
typedef long long int lli;

bool search(int from, int to, vector<int> &adj, vector<bool> &visited) {
	if(from == to) return true;
	if(visited[from]) return false;
	if(!visited[from]) visited[from] = true;
	bool flag = search(adj[from], to, adj, visited);
	return flag;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int nNodes, t;
	cin >> nNodes >> t;
	nNodes++; //Beggining with 1

	vector<int> adj(nNodes, 0);
	vector<bool> visited(nNodes, false);

	for(int i = 1; i < nNodes; i++) {
		cin >> adj[i];
		adj[i] = i + adj[i];
	}
	if(search(1, t, adj, visited)) cout << "YES" << endl;
	else cout << "NO" << endl;
}