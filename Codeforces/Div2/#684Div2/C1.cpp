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
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
/*
	11 12 13
	21 22 23

	1 1 0
	1 0 0

	
	20 21 22
*/

struct point {
	int x, y;
	point(int x, int y): x(x), y(y) {}
};

void update(vector<string> &grid, vector<vector<point>> &ans, vector<vector<bool>> &visited, point p1, point p2, point p3) {
	visited[p1.x][p1.y] = visited[p2.x][p2.y] = visited[p3.x][p3.y] = true;
	grid[p1.x][p1.y] = grid[p2.x][p2.y] = grid[p3.x][p3.y] = true;
	ans.pb({p1, p2, p3});
}

void check(int i, int j, int n, int m, vector<string> &grid, vector<vector<bool>> &visited, vector<vector<point>> &ans) {
	if((i+1 < n) && (j+1 < m) && (grid[i][j+1] == '1') && (grid[i+1][j] == '1')) {
		update(grid, ans, visited, point(i, j), point(i+1, j), point(i, j+1));
	} 
	else if(i-1 >= 0 && j+1 < m && (grid[i-1][j] == '1') && (grid[i][j+1] == '1')) {
		update(grid, ans, visited, point(i, j), point(i-1, j), point(i, j+1));
	} 
	else if((j-1 >= 0) && (i+1 < n) && (grid[i][j-1] == '1') && (grid[i+1][j] == '1')) {
		update(grid, ans, visited, point(i, j), point(i+1, j), point(i, j-1));
	} else if((i-1 >= 0) && (j-1 >= 0) && (grid[i-1][j] == '1') && (grid[i][j-1] == '1')) {
		update(grid, ans, visited, point(i, j), point(i-1, j), point(i, j-1));
	}
}
ostream &operator<<(ostream &os, const point & p){return os << p.x+1 << " " << p.y+1 << " ";}

void solve() {
	int n, m; cin >> n >> m;
	vector<string> grid(n, "");
	
	fore(i, 0, n) cin >> grid[i];

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<point>> ans;

	fore(i, 0, n) {
		fore(j, 0, m) {
			if(grid[i][j] == '1' && !visited[i][j]) check(i, j, n, m, grid, visited, ans);
		}
	}
	cout << ans.size() << endl;
	fore(i, 0, ans.size()) {
		fore(j, 0, ans[i].size()) cout << ans[i][j];
		cout << endl;
	}
}

int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}