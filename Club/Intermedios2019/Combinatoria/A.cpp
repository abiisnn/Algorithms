//https://codeforces.com/group/jbdVtsXBjp/contest/256461/problem/A
#include<bits/stdc++.h>
#define MAXN 10005
typedef long long lli;
using namespace std;
lli f[MAXN];

void precalcular() {
	f[0] = 1ll;
	f[1] = 1ll;
	for(lli i = 2ll; i < MAXN; i++) 
		f[i] = (i * f[i - 1]); 
}

lli combinacion(lli n, lli a, lli b) {
	return f[n] / (f[a] * f[b]);
}

int main() {
	lli n, sum = 0;
	cin >> n;
	precalcular();
	for(lli k = 1; k <= n; k++) 
		for(int i = 0, j = k; i <= k; i++, j--) 
			sum += combinacion(k, i, j);
	cout << sum << endl;
	return 0;
}