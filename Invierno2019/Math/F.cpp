#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MOD 1000000007
#define MAX 10000005
lli f[MAX];

void fac(lli n) {
	f[0] = f[1] = 1ll;
	for(int i = 2; i < n; i++) {
		f[i] = (f[i - 1] * i) % MOD;
	}
}

lli binPow(lli b, lli p) {
	lli res = 1;
	b %= MOD;
	while(p) {
		if(p & 1ll) res = (res * b) % MOD;
		p >>= 1l;
		b = (b * b) % MOD;
	}
	return res;
}
lli g(lli m, lli n) {
	lli a = (n * m);
	lli b = f[n];
	b = binPow(b, m) % MOD;
	lli inverso = binPow(b, MOD - 2) % MOD;
	return (f[a] * inverso) % MOD;
} 

int main() {
	int m, n;
	cin >> m >> n;
	fac(MAX);

	lli res = 0;
	for(int i = 0; i < n; i++) {
		res += g(m, __gcd(i, n));
		res %= MOD;
	}	
	lli inverso = (m * n) % MOD;
	inverso = binPow(inverso, MOD - 2) % MOD;

	res = (inverso * res) % MOD;
	cout << res << endl;
}