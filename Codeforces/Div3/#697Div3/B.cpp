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
	lli n; cin >> n;
	bool flag = false;
	for(int i = 0; i < 1000; i++) {
		lli op1 = n - 2020 * i;
		if((op1 == 0) or (op1 >= 0 && (op1 % 2021) == 0)) {
			flag = true; break;
		}

		op1 = n - 2021 * i;
		if((op1 == 0) or (op1 >= 0 && (op1 % 2020) == 0)) {
			flag = true; break;
		}
	}
	if(!flag) cout << "NO" << endl;
	else cout << "YES" << endl;
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}