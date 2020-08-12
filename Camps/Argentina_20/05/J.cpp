#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 26
#define INF 500000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<vector<int>> adj(MAX, vector<int>(0));
vector<vector<int>> m(MAX, vector<int>(MAX, INF));
vector<vector<int>> mem(MAX, vector<int>(MAX, -1));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));

int dfs(int from, int to) {
	if(visited[from][to]) return mem[from][to];
	if(from == to) return 0;
	visited[from][to] = true;
	int best = INF;
	fore(i, 0, adj[from].size()) {
		int children = adj[from][i];
		cout << "------->"<<from << " " << to << endl;
		cout << "mando dfs: " << children << " "<<to << endl;
		int minfrom = dfs(children, to);
		cout << "hijos de from:" << from << endl;
		cout << "hijo: " <<children << endl;
		cout << "ans: " << minfrom << endl;
		if(minfrom != INF) {
			cout << "si soy diferente: " << endl;
			minfrom += m[from][to];
			if(minfrom < best) best = std::min(best, minfrom);	
		} 
	}	
	return mem[from][to] = best;
}
void pre() {
	fore(i, 0, MAX) {
		fore(j, 0, MAX) {
			// cout << "dfs: " << i << " to: "<<j << endl;
			mem[i][j] = dfs(i, j);
			if(mem[i][j] != INF) {
				cout << "Aqui si: " << char(i+'a') << " to: " << char(j+'a') << " ans = " << mem[i][j] << endl;
			}
			// cout << "ans: " << mem[i][j]<<endl;;

		}
	}
	// fore(i, 0, MAX) {
	// 	fore(j, 0, MAX) {
	// 		cout << mem[i][j] << " ";
	// 	} cout << endl;
	// }
}

int main() {
	optimizar_io
	string a, b; cin >> a >> b;
	
	int n, w; cin >> n;
	char A, B;
	fore(i, 0, n) {
		cin >> A >> B >> w;
		int from = A - 'a', to = B - 'a';
		adj[from].pb(to);
		int act = m[from][to];
		if(w < act) m[from][to] = w;
	}
	if(a.size() != b.size()) {
		cout << -1 << endl;
		return 0;
	}
	// pre();
	int hola = dfs(1, 23);
	cout << "hola: " <<hola << endl;
	// lli total = 0;
	// string ans = "";
	// bool flag = true;
	// char newC;
	// int more;
	// fore(i, 0, a.size()) {	
	// 	newC = a[i];
	// 	if(a[i] != b[i]) {
	// 		if(!update(a[i]-'a', b[i]-'a', newC, more)) {
	// 			flag = false;
	// 			break;	
	// 		} 			
	// 		total += more;
	// 	}
	// 	ans += newC;
	// }
	// if(flag) {
	// 	cout << total << endl;
	// 	cout << ans << endl;
	// }
	// else cout << -1 << endl;
}