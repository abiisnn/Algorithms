
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli Divisors(lli n, lli k) {
	vector<lli> divs;
	for (lli i = 1; i * i <= n; i++) {
		if (!(n % i)) {
			divs.push_back(i);
			if (i * i != n) divs.push_back(n / i);
		}
	}
	sort(divs.begin(), divs.end());
	lli ans = 1;
 	for(int i = divs.size()-1; i >= 0; i--) {
		if(divs[i] <= k) {
			ans = divs[i];
			break;
		}
	}
	return ans;
}
int main() {
	optimizar_io
	int t;
	lli n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		if(k >= n) cout << 1 << endl;
		else {
			cout << n / Divisors(n, k) << endl;
		}
	}
}