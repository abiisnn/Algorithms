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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {

	int t;
	lli n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		lli ans = m * 2;
		if(n == 1) cout << 0 << endl;
		else if(n == 2) cout << m << endl;
		else cout << ans << endl;
	}
	return 0;
}