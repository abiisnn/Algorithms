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
#define MOD 1000000007
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
lli mod(lli a, lli b) { 
	return (b + (a % b)) % b; 
}
int main() {
	optimizar_io
	lli x, y, n;
	cin >> x >> y >> n;
	lli ans[6];
	lli lessOne = -1;
	x = mod(x, MOD), y = mod(y, MOD);
	ans[0] = mod(x, MOD), ans[1] = mod(y, MOD), ans[2] = mod(y - x, MOD);
	ans[3] =  mod(lessOne*x, MOD), ans[4] = mod(lessOne*y, MOD);
	ans[5] = mod(-y+x, MOD);
	cout << ans[(n-1)%6] << endl;;
}