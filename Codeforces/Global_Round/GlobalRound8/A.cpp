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

lli min(lli a, lli b) {
	if(a < b) return a;
	return b;
}
int main() {
	optimizar_io
	int t; cin >> t;
	lli a, b, n;
	while(t--) {
		cin >> a >> b >> n;
		if(a > b) swap(a, b);
		lli cont = 0;
		while(1) {
			if(a > n or b > n) break;
			cont++;
			if(cont & 1) a += b;
			else b += a;
		}
		cout << cont << endl;
	}
}