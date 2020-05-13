// https://codeforces.com/problemset/problem/939/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 10000005
typedef long long int lli;

bool search(int from, int to, vector<int> &adj) {
	bool flag = false;
	int index = adj[to];
	if(adj[index] == from) flag = true;
	return flag;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int nNodes, idGraph, neigh;
	int start, end;
	cin >> nNodes;
	nNodes++; //Beggining with 1

	vector<int> adj(nNodes, 0);

	for(int i = 1; i < nNodes; i++) cin >> adj[i];

	bool flag = false;
	for(int i = 1; i < adj.size(); i++) {
		if(search(i, adj[i], adj)) {
			flag = true;
			break;
		}
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}