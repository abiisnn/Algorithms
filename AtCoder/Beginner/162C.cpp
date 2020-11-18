#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(lli i = a; i <= b; i++)
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

int main() {
	optimizar_io
	lli k;
	cin >> k;
	lli ans = 0;
	fori(i, 1, k) {
		fori(j, 1, k) {
			fori(h, 1, k) {
				lli aux = __gcd(i, j);
				ans += __gcd(aux, h);
			}
		}
	}
	cout << ans << endl;
}