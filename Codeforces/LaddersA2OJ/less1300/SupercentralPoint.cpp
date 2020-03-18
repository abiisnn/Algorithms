#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

bool isSuperPoint(vector<pair<int, int>> &points, int p) {
	bool right = false, left = false, lower = false, upper = false;
	bool ans = false;
	int x = points[p].first, y = points[p].second;
	fore(i, 0, points.size()) {
		if(i == p) continue;
		if((points[i].first > x) && (points[i].second == y)) right = true;
		if((points[i].first < x) && (points[i].second == y)) left = true;
		if((points[i].first == x) && (points[i].second < y)) lower = true;
		if((points[i].first == x) && (points[i].second > y)) upper = true;		
	}
	if(right && left && lower && upper) ans = true;
	return ans;
}
int main() {
	optimizar_io
	int n, x, y;
	cin >> n;

	vector<pair<int, int>> points(n);
	fore(i, 0, n) {
		cin >> x >> y;
		points[i] = mk(x, y);
	}
	int ans = 0;
	fore(i, 0, n) {
		if(isSuperPoint(points, i)) {
			ans++;
		}
	}
	cout << ans << endl;
}