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

lli op1(lli a, lli b, lli x, lli y, lli n) {
	lli need = (a - x) + (b - y);
	n = min(n, need);
	lli aux = min(n, a-x); // QUITO TODO DE A
	a = a - aux;
	n = n - aux;
	aux = min(n, b-y); // QUITO TODO DE B
	b = b - aux;
	n = n - aux;
	return a * b;
}
void solve() {
	lli a, b, x, y, n; 
	cin >> a >> b >> x >> y >> n;
	cout << min(op1(a, b, x, y, n), op1(b, a, y, x, n)) << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}

