#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MOD 1000000007
typedef long long int lli;

lli mod(lli a, lli b) {
	if (a == 0)
		return 0;
	if(a > 0)
		return a % b;
	else
		return b - mod(a*(-1), b);
	
}
int main() {
	lli x, y, n, a1, a2, ans;
	cin >> x >> y >> n;
	a1 = x, a2 = y;
	a1 = mod(a1, MOD), a2 = mod(a2, MOD);

	if(n == 1) cout << mod(x, MOD) << endl;
	else if(n == 2) cout << mod(y, MOD) << endl;
	else {
		fore(i, 0, n - 2) {
			ans = mod(a2 - a1, MOD) ;
			a2 = mod(ans, MOD);
			a1 = mod(a2, MOD);
		}
		cout << mod(ans, MOD);
	}
}