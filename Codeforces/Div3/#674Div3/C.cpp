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
#define MAX 10000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	lli n; cin >> n;
	lli bestTimes = MAX;
	for(int i = 1; i <= sqrt(n); i++) {
		lli times = n / i;
		if(n % i) times++;
		times = i + times - 1;
		bestTimes = min(bestTimes, times);
	}
	cout << bestTimes-1 << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}