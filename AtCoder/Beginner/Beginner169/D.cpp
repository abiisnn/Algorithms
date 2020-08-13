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
#define MAX 1000000000000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void getPrimeFactors(lli n) {
	map<lli, int> pf;
	while(~n & 1) pf[2]++, n >>= 1;
	for (lli i = 3; i * i <= n; i += 2)
		while (!(n % i)) pf[i]++, n /= i;
	if (n > 1) pf[n]++;

	int ans = 0;
	for(auto &i: pf) {		
		int aux = i.se, cont = 1;
		while(aux - cont >= 0) {
			ans++;
			aux -= cont;
			cont++;
		}
	}
	cout << ans << endl;
}
int main() {
	optimizar_io
	lli n; cin >> n;
	getPrimeFactors(n);
}