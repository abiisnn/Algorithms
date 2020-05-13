// https://codeforces.com/problemset/problem/939/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 10000005
typedef long long int lli;

bool search(int from, int to, vector<vector<int>> &adj) {
	bool flag = false;
	int index = adj[to][0];
	if(adj[index][0] == from) flag = true;
	return flag;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int nNodes, neigh;
	cin >> nNodes;
	nNodes++; //Beggining with 1

	vector<vector<int>> adj(nNodes);
	for(int i = 0; i < nNodes; i++) {
		vector<int> aux;
		adj[i] = aux;
	}

	for(int i = 1; i < nNodes; i++) {
		cin >> neigh;
		adj[i].pb(neigh);
	}

	bool flag = false;
	for(int i = 1; i < adj.size(); i++) {
		vector<int> aux = adj[i];
		for(int j = 0; j < aux.size(); j++) {
			if(search(i, aux[j], adj)) {
				flag = true;
				break;
			}
		}
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}