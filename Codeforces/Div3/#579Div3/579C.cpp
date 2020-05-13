// https://codeforces.com/contest/1203/problem/C
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

lli divisor(lli n) {
	lli i = 0, cont = 0;
	set<lli> div;
	div.insert(n);
	for(lli i = 1; i*i <= n; i++) {
		if((n % i) == 0) {
			div.insert(i);
			div.insert(n/i);
		}
	}
	return div.size();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	lli n, number;
	cin >> n;
	cin >> number;
	lli g = number;
	for(int i = 0; i < n; i++) {
		cin >> number;
		g = __gcd(g, number);
	}
	lli counter = divisor(g);
	if(counter) cout << counter << endl;
	else cout << 1 << endl;
}