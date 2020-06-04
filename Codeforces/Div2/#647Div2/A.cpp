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

bool check(lli a, lli b) {
	int na = 0, nb = 0;
	for (int i = sizeof(a) * 8 - 1; ~i; i--) {
		if((a >> i) & 1) na++;
		if((b >> i) & 1) nb++;
	}
	return na == nb;
}
int main() {
	optimizar_io
	int t; cin >> t;
	lli a, b;
	while(t--) {
		cin >> a >> b;
		// cout << a << " "<< b <<endl;
		bool flag = false;
		int ans, movs = 0;
		bool equal;
		
		if(a > b) {
			int cont = 0;
			for(int i = 0 ; i < sizeof(b)*8; i++) {
				if((a >> i) == b) {
					flag = true;
					movs = i;
					break;
				}
			}
			equal = check((a>>movs), a);
		} else {
			int cont = 0;
			for(int i = 0 ; i < sizeof(b)*8; i++) {
				if((a << i) == b) {
					flag = true;
					movs = i;
					break;
				}
			}
			equal = check((a<<movs), a);
		}
		if(flag && equal) {
			ans = movs / 3;
			int res = movs % 3;
			ans += (res ) / 2;
			res = res % 2;
			ans += res / 1;	
			cout << ans << endl;
		} else cout << -1 << endl;
	}
}