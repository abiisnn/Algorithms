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
#define MOD 1000000007
#define INV 500000004
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli gauss(lli n) {
	return (n * (n + 1ll)) * INV;
}

void solve() {
	lli N; cin >> N;

	if(N == 1) {
		cout << 1 << endl; return;
	}
	if(N == 2) {
		cout << 3 << endl; return;
	}
	lli total = 0;
	for(lli i = 1ll, aux = N; i <= N; i++, aux--) {
		total += ((gauss(aux) * i) % MOD);
		total %= MOD;
	}
	cout << total << endl;
}
int main() {

	int t; cin >> t;
	while(t--) solve();
}