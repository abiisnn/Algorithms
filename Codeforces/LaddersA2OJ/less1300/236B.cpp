#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(long long int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 1000005
#define MOD 1073741824
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> lp;
void lowestPrimeSieve(lli n) {
	lp.resize(n + 1, 1);
	lp[0] = lp[1] = 0;
	for(int i = 2; i <= n; ++i) lp[i] = (i & 1 ? i : 2);
	int limit = sqrt(n);
	for(int i = 3; i <= limit; i += 2)
		if(lp[i] == i)
			for(int j = i * i; j <= n; j += 2 * i)
				if(lp[j] == j) lp[j] = i;
}
lli factor(lli n) {
	lli ans = 1, aux = n;
	while(n > 1) {
		int p = lp[n];
		int r = 0;
		while((n % p) == 0) {
			n /= p;
			r++;
		}
		ans *= (r + 1);
	}
	return ans;
}

int main() {
	optimizar_io
	lowestPrimeSieve(MAX);
	lli a, b, c;
	cin >> a >> b >> c;
	vector<int> numDiv(MAX);
	fore(i, 0, MAX) {
		numDiv[i] = factor(i);
	}
	lli ans = 0;
	fori(i, 1, a) {
		fori(j, 1, b) {
			fori(k, 1, c) {
				lli n = i * j * k;
				ans = (ans + numDiv[n]) % MOD;
			}	
		}
	}
	cout << ans << endl;
}
