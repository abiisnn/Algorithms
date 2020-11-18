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
#define MAX 100000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<vector<int>> numberDivisors(257, vector<int>());
// O(sqrt(N))
int getDivisors(lli n) {
	int divs = 0;
	for (lli i = 1; i * i <= n; i++)
		if (!(n % i)) {
			divs++;
			if (i * i != n) divs++;
		}
	return divs;
}
void solve() {
	lli y, k;
	cin >> y >> k;
	if(!numberDivisors[k].size()) {
		cout << -1 << endl;
		return;
	}
	lli beuty = 1000000000009, best = -1;
	for(int i = 0; i < numberDivisors[k].size(); i++) {
		lli auxB = abs(numberDivisors[k][i] - y);
		if(auxB < beuty) {
			beuty = auxB;
			best = numberDivisors[k][i];
		}
	}
	cout << best << endl;
}

int main() {
	optimizar_io
	fore(i, 0, MAX) {
		int aux = getDivisors(i);
		numberDivisors[aux].pb(i);
	}
	int t; cin >> t;
	while(t--) {
		solve();		
	}
}