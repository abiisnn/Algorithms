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

void solve() {
	int n, k; cin >> n >> k;
	vector<lli> v(n * k);
	fore(i, 0, n*k) cin >> v[i];

	lli total = 0;
	int time = n / 2 + 1;
	for(int i = 0, j = n*k  - time; i < k; i++, j -= time) total += v[j];
	
	cout << total << endl;
	
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();	
}

/*

3 94 99
11 69 
*/