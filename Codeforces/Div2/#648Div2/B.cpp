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
 
void solve() {
	int n; cin >> n;
	vector<int> v(n), t(n);
	fore(i, 0, n) cin >> v[i];
	fore(i, 0, n) cin >> t[i];
	bool flag = true;
	fore(i, 0, n-1) {
		if(v[i+1] < v[i]) flag = false;
	}
	if(flag) {cout << "Yes"<<endl; return;}
	int zero = 0;
	fore(i, 0, n) {
		if(!t[i]) zero++;
	}
	if((zero != n) && (zero != 0)) cout << "Yes" << endl;
	else cout << "No" << endl;
}
 
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) {
		solve();
	}
}