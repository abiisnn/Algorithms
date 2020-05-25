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

int main() {
	optimizar_io
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> c(n);
	map<int, int> bucket;
	fore(i, 0, n) {
		cin >> c[i].fi;
		c[i].se = i;
		bucket[c[i].fi]++;
	}
	bool flag = true;
	for(auto &i: bucket) {
		if(i.se >= k+1) flag = false;
	}
	if(flag) {
		sort(c.begin(), c.end());
		vector<int> ans(n);
		cout << "YES" << endl;
		fore(i, 0, c.size()) {
			ans[c[i].se] = (i % k)+1;
		}
		fore(i, 0, ans.size()) {
			cout << ans[i] << " ";
		}
	} else cout << "NO" << endl;
	
	
}