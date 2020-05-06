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

lli minN(lli a, lli b) {
	if(a < b) return a;
	return b;
}

int main() {
	optimizar_io
	lli n, k;
	cin >> n >> k;

	if((n < 3) && (n == k)) {
		fore(i, 0, n) cout << "a";
	}
	else if((minN(3, n) <= k) && k <= n) {
		fore(i, 0, k - minN(n, 3)) cout << "x";
		string pattern = "abc";
		int s = n - (k - minN(n, 3));
		fore(i, 0, s) cout << pattern[i % 3];
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
}