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
#define MAX 1000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
 
bool check(lli n, set<int> &divs) {
	int mine = 0;
	for(lli i = 1ll; i * i <= n; i++) {
		if (!(n % i)) {
			if(i != 1 && i != n) {
				mine++;
				if(!divs.count(i)) return false;
			}
			if (i * i != n) {
				if((n/i) != 1 && (n/i) != n) {
					mine++;
					if(!divs.count(n/i)) return false;;
				}
			}
		}
	}
	if(mine != divs.size()) return false;
	return true;
}
void solve() {
	int n, d; cin >> n;
	set<int> divs;
	lli greater = 0, less = MAX;
	fore(i, 0, n) {
		cin >> d;
		if(d > greater) greater = d;
		if(d < less) less = d;
		divs.insert(d);
	}
	lli num = greater * less;
	if(check(num, divs)) cout << num << endl;
	else cout << -1 << endl;
}
 
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) {
		solve();
	}
}