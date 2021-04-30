#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

int main() {
	int t;
	lli n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		lli ans = ((n + 1ll) * (n + 2ll)) % MOD;
		ans = (ans * (k + 1ll)) % MOD;
		ans = (ans * 500000004) % MOD;
		cout << ans << endl;
	}
	return 0;
}