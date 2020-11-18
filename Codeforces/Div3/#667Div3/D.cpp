#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int sumDigits(lli n) {
	int sum = 0;
	while(n) {
		sum += (n % 10ll);
		n /= 10ll;
	}
	return sum;
}
void solve() {
	lli n; int s;
	cin >> n >> s;
	lli ite = 0, ten = 1, aux = n;
	while(sumDigits(n) > s) {
		int dig = (n / ten) % 10;
		lli dif = (10 - dig) * (ten);
		n += dif;
		ite += dif;
		ten *= 10;
	}
	cout << ite << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}