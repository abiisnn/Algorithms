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

int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> v(n);
	fore(i, 0, n) cin >> v[i];

	vector<lli> acum(n+1, 0);
	if(n > 0) {
		acum[0] = v[0];		
	}
	for(int i = 1, j = 1; i < n; i++, j++) {
		acum[j] = acum[j-1] + v[i];
	}
	int q; cin >> q;
	fore(i, 0, q) {
		int l, r; cin >> l >> r;
		lli lim = 0;
		if(l-1 >= 0) lim = acum[l-1];
		cout << acum[r] - lim << endl;
	}
}