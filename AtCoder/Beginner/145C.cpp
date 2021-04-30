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

// x1, y1, x2, y2
lli getDistance(pair<int, int> &a, pair<int, int> &b) {
	return ((a.fi - b.fi) * (a.fi - b.fi)) + ((a.se - b.se) * (a.se - b.se)); 
}

int main() {
	optimizar_io
	int n; cin >> n;
	vector<pair<int, int>> points(n, mk(0, 0));

	fore(i, 0, n) cin >> points[i].first >> points[i].second;
	
	vector<int> v(n);
	fore(i, 0, n) v[i] = i;
	vector<lli> fact(n+1);
	fact[0] = fact[1] = 1ll;
	fore(i, 2ll, n+1) fact[i] = fact[i-1] * i;

	ld distance = 0.0;
	do {
		fore(i, 0, n-1) distance += sqrt(getDistance(points[v[i]], points[v[i+1]]));
	} while(next_permutation(all(v)));

	distance /= fact[n];
	cout.precision(10);
	cout << fixed << distance << endl;
}