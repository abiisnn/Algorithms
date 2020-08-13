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
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
map<pair<int, int>, lli> L;
struct LCA {
    vector<int> euler, first, segtree;
    vector<lli> height;
    vector<bool> visited;
    int n;
    LCA(vector<vector<pair<int, lli>>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }
    void dfs(vector<vector<pair<int, lli>>> &adj, int node, lli h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to.fi]) {
                dfs(adj, to.fi, h + to.se);
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

void solve(int n) {
    int q, ax, u, v;
    lli h;
    vector<vector<pair<int, lli>>> adj(n, vector<pair<int, lli>>(0));
    fore(i, 1, n) {
        cin >> ax >> h;
        adj[i].pb(mk(ax, h));
        adj[ax].pb(mk(i, h));
    }
    LCA *aux = new LCA(adj, 0);
    cin >> q;    
    while(q--) {
        cin >> u >> v;
        int nodeLCA = aux->lca(u, v);
        lli ans = aux->height[u] + aux->height[v] - 2ll*aux->height[nodeLCA];
        cout << ans;
        if(q) cout << " ";
    }
}
int main() {
	optimizar_io
    int n;
    while(cin >> n, n) {
        solve(n);
        cout << endl;
    }
}