#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 10005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, parent; cin >> n;
	vector<vector<int>> adj(n+1, vector<int>(0));
	fore(i, 1, n) {
		cin >> parent;
		adj[parent].pb(i+1);
	}
	bool flag = true;
	fore(i, 1, adj.size()) {
		int leaf = 0;
		fore(j, 0, adj[i].size()) {
			if(!adj[adj[i][j]].size()) leaf++;
		}
		if(!adj[i].size()) continue;
		if(leaf < 3) {
			flag = false;
			break;
		}
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}