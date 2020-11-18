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

	lli greater = 0;
	fore(i, 0, n) {
		cin >> v[i];
		greater = max(greater, v[i]);
	}
	bool flag = false;
	int pos = -1;
	for(int i = 0; i < n; i++) {
		if(v[i] == greater) {
			if(i >= 1 && v[i-1] < greater) {
				pos = i;
				flag = true;
				break;
			}
			if(i < n-1 && v[i+1] < greater) {
				pos = i;
				flag = true;
				break;
			}
		}
	}
	if(flag) cout << pos+1 << endl;
	else cout << -1 << endl;
}
int main() {
	int t; cin >> t;

	while(t--) solve();
}