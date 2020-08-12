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
#define C 3
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	int n; cin >> n;
	vector<int> v(2*n);
	fore(i, 0, 2*n) cin >> v[i];
	set<int> exist;

	fore(i, 0, 2*n) {
		if(!exist.count(v[i])) cout << v[i] << " ";
		exist.insert(v[i]);
	}
	cout << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;

	while(t--) {
		solve();
	}
}
