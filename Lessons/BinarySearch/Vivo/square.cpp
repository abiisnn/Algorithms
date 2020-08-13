#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli isSquare(lli n) {
	lli l = 0, r = n; //[0, n]
	while(l <= r) {
		lli m = l + (r - l) / 2ll;
		if(m * m == n) return m;
		if(m * m > n) r = m - 1;
		else l = m + 1; 
	}
	return -1;
}
int main() {
	lli n; cin >> n;
	lli ans = isSquare(n); // -1 no, ans si
	if(ans != -1) {
		cout << "Su raiz exacta es: " << ans << endl;
	} else cout << "No tiene" << endl;
}