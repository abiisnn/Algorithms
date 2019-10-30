// https://omegaup.com/arena/problem/Dibujando-Montanas#problems
#include<bits/stdc++.h>
#define MAXN 10010
#define MOD 1234567
typedef long long int lli;
using namespace std;

lli f[MAXN];
lli c[MAXN];
void precalcular() {
	f[0] = 1ll;
	f[1] = 1ll;
	for(lli i = 2ll; i < MAXN; i++) 
		f[i] = (i * f[i - 1]) % MOD; 
}
lli powerMod(lli b, lli e) {
	lli ans = 1;
	b %= MOD;
	while(e) {
		if(e & 1) ans = (ans * b) % MOD;
		e >>= 1;
		b = (b * b) % MOD;
	}
	return ans;
}
lli combinacion(lli n) {
	lli inverso = (f[n] * f[n + 1]) % MOD;
	inverso = powerMod(inverso, MOD - 2) % MOD;
	return (f[2 * n] * inverso) % MOD;
}

void catalan() {
	f[0] = 1;
	for(int n = 1; n <= MAXN; n++) {
		for(int i = 0; i < (n - 1); i++) 
			f[n] = (f[n] + f[i] * f[n - i - 1]) % MOD;
	}
	for(int i = 0; i < 10; i++)
		cout << f[i] << " ";
}
int main() {
	lli n;
	cin >> n;
//	precalcular();
	catalan();
	cout << f[n] << endl;
}