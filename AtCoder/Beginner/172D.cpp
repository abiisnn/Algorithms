#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
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

lli sumDiv(int n) {
	int div = 0;
	for(lli i = 1ll; i * i <= n; i++) {
		if(!(n % i)) {
			div++;
			if(i * i != n) div++;
		}
	}
	lli ans = (lli)n * div;
	cout << n <<" div: " << div << endl;
	return ans;
}

int main() {
	optimizar_io
	int n; cin >> n;
	lli ans = 0;
	fori(i, 1, n) {
		ans += sumDiv(i);
	}
	cout << ans << endl;
}