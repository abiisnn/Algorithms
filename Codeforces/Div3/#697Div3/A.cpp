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

void solve() {	
	lli n; cin >> n;
	while((n % 2) == 0) {
		n /= 2ll;
	}
	if((n & 1) && n != 1) cout << "YES" << endl;
	else cout << "NO" << endl;	
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}