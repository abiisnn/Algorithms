#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool isSquare(lli n) {
	lli l = 0, r = n;
	while(l <= r) {
		lli mid = l + (r - l) / 2ll;
		lli actual = mid * mid;
		if(actual == n) return true;
		if(actual < n) l = mid + 1;
		else r = mid - 1;
	}
	return false;
}
int main() {
	lli n; cin >> n;
	if(isSquare(n)) cout << "Yes" << endl;
	else cout << "No" << endl;
}