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
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
map<int, string> m;
map<string, int> bucket;
vector<int> dp;
vector<bool> visited(MAX, false);
int current = 1; 

vector<vector<int>> adj(MAX, vector<int>(0));
int hola = 0;
int add(string u, int &current) {
	m[current] = u;
	bucket[u] = current;
	return current++;	
}
int compare(int u, int v) {
	string aU = m[u], aV = m[v];
	int ans = 0;
	if(aU.size() == aV.size()) {
		ans = v;
		for(int i = 0; i < aV.size(); i++) {
			if(aV[i] == aU[i]) continue;
			if(tolower(aU[i]) < tolower(aV[i])) {
				ans = u;
				break;
			}
		}
	} else if(aU.size() < aV.size()) ans =  u;
	else ans = v;
	return ans;
}
int dfs(int u, int last, int best) {
	if(visited[u]) return dp[u];
	if(u >= current) {
		return dp[u] = compare(best, u);
	}
	visited[u] = true;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(v != last) {
			int auxBest = dfs(v, u, best);
			best = compare(best, auxBest);
		}
	}
	if(last != -1) best = compare(best, u);
	return dp[u] = best;
}

int main() {
	optimizar_io
	int n; cin >> n;
	fore(i, 0, n) {
		string u, v;
		cin >> u >> v;
		int nu = bucket[u], nv = bucket[v];
		if(!nu) nu = add(u, current);
		if(!nv) nv = add(v, current);
		adj[nu].pb(nv);
		adj[nv].pb(nu);
	}
	m[current] = "ZZZZZZZZZZZZZZZZZZZZZZZ";
	dp.resize(MAX, current);

	vector<string> v;
	string actual;
	while(cin >> actual) {
		v.pb(actual);
	}

	fore(i, 0, v.size()) {
		int ans = dfs(bucket[v[i]], -1, current);
		if(ans == current) {
			cout << v[i];
		} else cout << m[ans];
		cout << " ";
	}

}