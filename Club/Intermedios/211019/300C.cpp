// https://codeforces.com/problemset/problem/300/C
#include<bits/stdc++.h>
#define MAXN 1000009
#define MOD 1000000007
typedef long long int lli;
using namespace std;

lli f[MAXN];

int isPerfect(lli n, int A, int B) {
	lli aux = n;
	while(n) {
		aux = n % 10; 
		if((aux == A) || (aux == B)) n /= 10;		
		else return 0;
	}
	return 1;
}

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

lli combinacion(int n, int a, int b) {
	lli inverso = (f[a] * f[b]) % MOD;
	inverso = powerMod(inverso, MOD - 2) % MOD;
	return (f[n] * inverso) % MOD;
}
int main() {
	int a, b, n;
	lli numero, sum = 0;
	cin >> a >> b >> n;
	precalcular();
	// Generate GOOD
	for(int i = 0, j = n; i <= n; i++, j--) {
		numero = ((i * a) + (j * b)) % MOD;
		if(isPerfect(numero, a, b)) {
			// Obtener combinacion del numero
			sum += combinacion(n, i, j);
			sum %= MOD;
		}
	}
	cout << sum;
}

