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

int calculate(int c0, int c1, int cont0, int cont1) {
	return (c0 * cont0) + (c1 * cont1);
}

void solve() {
	int n, c0, c1, h; 
	cin >> n >> c0 >> c1 >> h;

	string s; cin >> s;
	int cont0 = 0, cont1 = 0;
	for(char &i: s) if(i == '0') cont0++;
	cont1 = n - cont0;
	int op1 = calculate(c0, c1, cont0, cont1);
	int op2 = (h * cont0) + calculate(c0, c1, 0, n);
	int op3 = (h * cont1) + calculate(c0, c1, n, 0); 
	cout << min(op1, min(op2, op3)) << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;

	while(t--) solve();	
}