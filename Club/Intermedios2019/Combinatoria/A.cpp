//https://codeforces.com/group/jbdVtsXBjp/contest/256461/problem/A
#include<bits/stdc++.h>
#define MAXN 57
typedef long long int lli;
using namespace std;
lli f[MAXN];

void precalcular() {
	f[0] = 1ll;
	f[1] = 2ll;
	for(lli i = 2ll; i < MAXN; i++) 
		f[i] = f[i - 1] * 2; 
}

int main() {
	lli n, sum = 0;
	cin >> n;
	precalcular();
	for(lli i = 1; i <= n; i++) 
		sum += f[i];
	cout << sum;
	return 0;
}