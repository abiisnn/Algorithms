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
#define MAX 31
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];
	
	int areEquals = 0;
	long int totalSum = 0;
	fore(i, 0, n) {
		if(v[i] == x) areEquals++;
		totalSum += (x - v[i]);
	}

	if(areEquals == n) cout << 0 << endl;
	else if(areEquals > 0) cout << 1 << endl;
	else if(totalSum == 0) cout << 1 << endl;
	else cout << 2 << endl;
}
int main() {
    optimizar_io
    int t; cin >> t;
    while(t--) solve();
}

