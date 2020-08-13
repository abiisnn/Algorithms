#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 1e18
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> v(n);
	bool zero = false;
	fore(i, 0, n) {
		cin >> v[i];
		if(!v[i]) zero = true;
	}
	if(zero) {cout << 0 << endl; return 0;}
	lli ans = 1;
	fore(i, 0, n) {
		if(v[i] <= (1000000000000000000 / ans)) ans = ans * v[i];
		else {	
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}