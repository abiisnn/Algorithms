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
#define MAX 100005
#define MOD 1000000007 
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<bool> isPrime;
vector<int> H(MAX);
vector<int> mem(MAX, -1);

void primesSieve(int n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]){
		if(i <= limit)
			for(int j = i * i; j <= n; j += 2 * i) isPrime[j] = false;
		}
	}
}
int dfs(vector<vector<int>> &graph, int i) {
	// cout << i + 1;
	if(isPrime[H[i]]) return 0;
	if(mem[i] != -1) return mem[i];
	// cout <<" no soy primo" << endl;
	int lon = 0;
	for(int j = 0; j < graph[i].size(); j++) {
		lon += dfs(graph, graph[i][j]);
		
	}
	return mem[i] = 1 + lon;
}
int main() {
	optimizar_io
	int n, u, v; cin >> n;
	vector<vector<int>> graph(n, vector<int>(0));
	fore(i, 0, n) {
		cin >> H[i];
	}
	primesSieve(n+1);
	fore(i, 0, 20) cout << i << " "<< isPrime[i] << endl;
	fore(i, 0, n-1) {
		cin >> u >> v;
		graph[u-1].pb(v-1);
	}
	fore(i, 0, graph.size()) {
		cout << "Node: " << i +1<< " ";
		fore(j, 0, graph[i].size()) {
			cout << graph[i][j] +1<< " ";
		}
		cout << endl;
	}
	int maxLong = 0;
	cout << endl;
	fore(i, 0, graph.size()) {
		int d = dfs(graph, i);
		cout << "dfs desde: " << i+1 << " es: " << d << endl;
		if(d > maxLong) maxLong = d;
	}
	cout << maxLong << endl;
}