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
#define MAX 100000000000000;
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	int n; lli k; cin >> n >> k;
	map<lli, int> bucket;
	fore(i, 0, n) {
		lli aux; cin >> aux;
		lli num = (k - (aux % k)) % k;
		bucket[num]++;
	}
	lli number = -1, freq = 0, key = 0;
	for(auto &i: bucket) {
		if(!i.fi) continue;
		if(i.se > freq) {
			freq = i.se;
			number = i.fi;
		}
	}
	for(auto &i: bucket) {
		if(i.se == freq) {
			key = i.fi;
		} 
	}
	if(number != -1) {
		lli ans = (freq - 1) * k;
		if(key) ans += key + 1;
		cout << ans << endl;
	} else cout << 0 << endl;
	
}

int main() {
	int t; cin >> t; 
	while(t--) {
		solve();
	}
}
