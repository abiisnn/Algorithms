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
	int n; cin >> n;
	vector<lli> v(n);
	fore(i, 0, n) cin >> v[i];
	
	bool isDec = true;
	for(int i = 0; i < n-1; i++) {
		if(v[i + 1] >= v[i]) {
			isDec = false;
			break;
		}
	}

	if(isDec) cout << "NO";
	else cout << "YES";
	cout << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}