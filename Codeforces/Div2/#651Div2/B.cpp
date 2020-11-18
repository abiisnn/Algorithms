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
	vector<int> odd, even;
	for(int i = 0; i < 2 * n; i++) {
		int num; cin >> num;
		if(num & 1) odd.pb(i+1);
		else even.pb(i+1);
	}
	vector<pair<int, int>> ans;
	for(int i = 0; i < odd.size(); i+=2) {
		if(i + 1 < odd.size()) {
			ans.push_back(mk(odd[i], odd[i+1]));
		}
	}
	for(int i = 0; i < even.size(); i+=2) {
		if(i + 1 < even.size()) {
			ans.push_back(mk(even[i], even[i+1]));
		}
	}
	fore(i, 0, n-1) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}

/*
	even:
	odd + odd = even
	even + even = even
	odd + even = odd

	1 2 3 4 5 6
	1+3, 2+4,  

	5 7 9 10
	5+7
*/