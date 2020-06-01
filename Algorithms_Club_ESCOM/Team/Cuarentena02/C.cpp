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
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];
	if(n <= 4) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> firstPart, secondPart;
	for(int i = 0; i < n; i++) {
		if(i & 1) secondPart.pb(v[i]);
		else firstPart.pb(v[i]);
	}
	
	vector<int> ans(n);
	fore(i, 0, firstPart.size()) {
		ans[i] = firstPart[i];
	}
	ans[firstPart.size()] = secondPart[0];
	ans[n-1] = secondPart[1];
	fore(i, 0, secondPart.size()-2) {
		ans[firstPart.size()+1+i] = secondPart[i+2];
	}
	fore(i, 0, n) cout << ans[i] << " ";
	cout << endl;
	
}