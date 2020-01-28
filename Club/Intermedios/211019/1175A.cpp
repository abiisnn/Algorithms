// https://codeforces.com/problemset/problem/1175/A
#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli cont(lli a, lli b) {
	lli cont = 0;
	lli aux = 0;
	while(a) {
		aux = (a % b);
		a -= aux;
		a /= b;
		cont += aux;
		cont++;
	}
	return cont - 1;
}
int main() {
	int tc;
	lli n, k;
	cin >> tc;
	while(tc--) {
		cin >> n >> k;
		cout << cont(n, k) << endl;
	}
}