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
#define MAX 205
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<bool> visited(MAX, false);

bool bicoloring(vector<vector<int>> &adj) {
    vector<int> color((int)adj.size(), -1);
   
    for(int i = 0; i < (int)adj.size(); i++) {
        if(color[i] > -1) continue;

        color[i] = 0;
        queue<int> bfs;
        bfs.push(i);
        
        while(!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            for(auto &v: adj[u]) {
                if(color[v] < 0) {
                    bfs.push(v);
                    color[v] = !color[u];
                }
                if(color[v] == color[u]) {
                    return false;
                }
            }
        }
   }
   return true;
}
void solve(int n) {
    vector<vector<int>> adj(n, vector<int>(0));
    int conexion; cin >> conexion;
    for(int i = 0; i < conexion; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(bicoloring(adj)) cout << "BICOLORABLE.";
    else cout << "NOT BICOLORABLE.";   
    cout << endl;
}

int main() {
    optimizar_io
    int n;
    while(cin >> n, n) {
        solve(n);
    }
}