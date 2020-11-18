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
#define MAX 27
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<vector<char>> adj(MAX, vector<char>(0));
vector<int> indegree(MAX, 0), topo;
vector<bool> can(MAX, false);
set<int> exist;

bool topological() {
    queue<int> bfs;
    int exp = 0, cont = 0;
    fore(i, 0, indegree.size()) {
        if(can[i] && !indegree[i]) bfs.push(i);
        if(can[i]) exp++;
    }
    while(!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();
        topo.pb(u);
        exist.insert(u);

        fore(i, 0, adj[u].size()) {
            int v = adj[u][i];
            if(!--indegree[v]) bfs.push(v);
        }
        cont++;
    }
    return cont == exp;
}
int main() {
    optimizar_io
    int n; cin >> n;
    vector<string> data(n, "");
    for(int i = 0; i < n; i++) cin >> data[i];

    bool flag = true;
    fore(i, 0, n-1) {
        int equals = 0;
        fore(j, 0, min((int)data[i].size(), (int)data[i+1].size())) {
            char u = data[i][j], v = data[i+1][j];
            if(u == v) {
                equals++;
                continue;    
            }
            adj[u-'a'].pb(v-'a');
            can[u-'a'] = can[v-'a'] = true;
            indegree[v-'a']++;
            break;
        }
        if(equals == min((int)data[i].size(), (int)data[i+1].size()) && data[i].size() > data[i+1].size()) {
            flag = false;
            break;        
        }

    }
    if(topological() && flag) {
        int first;
        bool existTopo = false;
        if(topo.size()) {
            first = topo[0];
            existTopo = true;
        }
        string ans = "";
        for(int i = 0; i < MAX - 1; i++) {
            if(existTopo && (i == first)) { 
                fore(j, 0, topo.size()) ans.pb(topo[j]+'a');
            } else if(exist.count(i)) continue;
            else ans.pb('a' + i);
        }
        cout << ans << endl;
    } else cout << "Impossible";

}