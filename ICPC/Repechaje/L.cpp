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
#define MAX 10000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> lp;
void lowestPrimeSieve(lli n) {
	lp.resize(n + 1, 1);
	lp[0] = lp[1] = 0;
	for(int i = 2; i <= n; ++i) lp[i] = (i & 1 ? i : 2);
	int limit = sqrt(n);
	for(int i = 3; i <= limit; i += 2)
		if(lp[i] == i)
			for(int j = i * i; j <= n; j += 2 * i)
				if(lp[j] == j) lp[j] = i;
}

void factor(lli n, set<lli> &pf) {
	while(n > 1) {
		int p = lp[n];
		int r = 0;
		while((n % p) == 0) {
			n /= p;
			r++;
		}
		pf.insert(p);
	}
}
 
int main() {
	int t; cin >> t;
	lowestPrimeSieve(MAX);
	while(t--) {
		lli a, b; cin >> a >> b;
		set<lli> total;
		factor(a, total);
		factor(b, total);
		cout << total.size() << endl;
	}
}