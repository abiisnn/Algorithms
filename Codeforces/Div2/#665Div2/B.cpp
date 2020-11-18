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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	lli xa, ya, za, xb, yb, zb;
	cin >> xa >> ya >> za;
	cin >> xb >> yb >> zb;

	lli total = 0;
	lli aux = min(za, yb); // 2 y 1  x = 0, y = 1, z = 2
	za -= aux; yb -= aux;
	total += (aux * 2 * 1); 
	// 1 y 0
	aux = min(ya, xb);
	ya -= aux; xb -= aux;
	// 2 y 0
	aux = min(za, xb);
	za -= aux, xb -= aux;

	// 0 0
	aux = min(xa, xb);
	xa -= aux; xb -= aux;
	//  1 1
	aux = min(ya, yb);
	ya -= aux; yb -= aux;
	// 2 2
	aux = min(za, zb);
	za -= aux; zb -= aux;


	// 0 2
	aux = min(xa, zb);
	xa -= aux, zb -= aux;
	// 0, 1
	aux = min(xa, yb);
	xa -= aux; yb -= aux;
	// 1, 2
	aux = min(ya, zb);
	total -= (aux * 2 * 1);
	cout << total << endl;
}

int main() {
	optimizar_io
	int t; cin >> t;

	while(t--) {
		solve();
	}
}