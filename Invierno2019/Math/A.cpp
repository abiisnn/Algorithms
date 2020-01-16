#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define MAX 100001

lli length(lli n) {
	int d = to_string(n).size(); 
	lli l = n, r = n - 8, ans = 0;
	if(r <= 0) r = 1;
	for(int i = 0; i <= d; ++i) {
		ans += sum(r, l) * i;
		l = r - 1;
		r = r - 9 * power(10, i);
		if(r <= 0) r = 1;
	}
	return ans;
}

lli sum(lli a, lli b) {
	return b * (b + 1) / 2 - a * (a - 1) / 2;
}
// Longitud de un bloque hasta el m-esimo grupo.


// Hallar la minima n tal que k <= length2(n)


int main() {

}