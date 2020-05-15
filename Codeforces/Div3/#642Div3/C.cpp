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
#define MAX 500005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> perimetro(MAX);
void solve(int n) {
	if(n == 1) {
		cout << 0 << endl;
		return;
	}
	vector<lli> p;
	while(n > 1) {
		if(n <= 1) break;
		p.pb(perimetro[n]);
		n -= 2;
	}
	lli ans = 0;
	lli cont = p.size();
	fore(i, 0, p.size()) {
		ans += (p[i] * cont);
		cont--;
	}
	cout << ans << endl;
}
int main() {
	optimizar_io
	perimetro[0] = 0, perimetro[1] = 1;
	fore(i, 3, MAX) {
		perimetro[i] = (i * 4) - 4;
	}
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		solve(n);
	}
}