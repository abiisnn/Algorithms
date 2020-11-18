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
#define MAX 2505
#define N 52
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<vector<pair<int, int>>> buc(MAX, vector<pair<int, int>> (0));
vector<vector<bool>> visited(N, vector<bool>(N, false));
vector<vector<int>> mem(N, vector<int>(N));

int distance(pair<int, int> &p1, pair<int, int> &p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
} 
lli dfs(int current, pair<int, int> &p, int k) {
	if(visited[p.first][p.second]) return mem[p.first][p.second];
	if(current == k) return 0;
	if(buc[current].size() == 0 && current < k) return INT_MAX;

	visited[p.first][p.second] = true;
	int minHere = INT_MAX;
	int pointPos = -1;
	for(int i = 0; i < buc[current + 1].size(); i++) {
		int dis = distance(p, buc[current + 1][i]);
		int m =  dfs(current + 1, buc[current+1][i], k);
		if(m != INT_MAX && (m + dis < minHere)) {
			minHere = m + dis;
			pointPos = i;
		}
	}
	if(pointPos == -1) return mem[p.first][p.second] = INT_MAX;
	return mem[p.first][p.second] = minHere;
}

int main() {
	optimizar_io
	int n, k; cin >> n >> k;

	fore(i, 0, n) {
		fore(j, 0, n) {
			int num; cin >> num;
			buc[num].pb(make_pair(i, j));
		}
	}

	int ans = INT_MAX;
	for(int i = 0; i < buc[1].size(); i++) {
		int m = dfs(1, buc[1][i], k);
		ans = min(ans, m);
	}
	if(ans == INT_MAX) ans = -1;
	cout << ans << endl;
}