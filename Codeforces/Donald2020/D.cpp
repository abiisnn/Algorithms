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
#define MOD 1000000007
#define INF 500000
#define MAX 1000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
 	lli n;
 	cin >> n; 
 	lli sq = sqrt(n);
 	lli ans = 0, i = 1ll, j = 1ll, aux = 0, cont = 2ll;
 	lli sumTotal = 0;
 	while(i < sq) {
 		lli agrego = (((i * i) % MOD) * 2ll) % MOD;
 		ans += agrego;
 		ans %= MOD;
 		sumTotal += (i * 2ll);
 		cont += 2ll;
 		i++;
 	}
 	
 	cout << "ans: " << ans << endl;
 	lli falta = n - sumTotal;
 	ans += (falta * sq) % MOD;
 	cout << ans << endl;
}