#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<int> preorden(MAX);
bool comp(int a, int b) {
    return preorden[a] < preorden[b];
}
struct LCA {
    vector<int> euler, first, segtree;
    vector<int> height;
    vector<bool> visited;
    int n;
    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        int time = 0;
        dfs(adj, root, 0, time);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }
    void dfs(vector<vector<int>> &adj, int node, int h, int &time) {
        preorden[node] = time;
        time++;
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        preorden.pb(node);
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1, time);
                euler.push_back(node);
            }
        }
    }
    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }
    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;
        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }
    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};
int main() {
	optimizar_io
    int m, n, root; cin >> n >> m;
    vector<vector<int>> P(m, vector<int>(0));
    vector<vector<int>> adj(n, vector<int>(0));
    fore(i, 0, n) {
        int emp;
        cin >> emp;
        P[emp-1].pb(i);
    }
    fore(i, 0, n) {
        int u;
        cin >> u;
        if(!u) root = i;
        else {
            adj[u-1].pb(i);
            adj[i].pb(u-1);
        }
    }
    LCA *aux = new LCA(adj, root);
    fore(i, 0, m) {
        sort(all(P[i]), comp);
        lli ans = aux->height[P[i][0]] + 1;
        fore(j, 1, P[i].size()) {
            int lca_uv = aux->lca(P[i][j-1], P[i][j]);
            ans += aux->height[P[i][j]] - aux->height[lca_uv]; 
        }
        cout << ans << " ";
    } cout << endl;
}