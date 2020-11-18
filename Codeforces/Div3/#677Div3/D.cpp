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
	vector<pair<lli, int>> a(n, make_pair(0,0)); 
	fore(i, 0, n) {
		cin >> a[i].first;
		a[i].second = i+1; 
	}
	sort(all(a));
	if(a[0].first == a[n-1].first) {
		cout << "NO" << endl;
		return;
	}
	vector<pair<int, int>> ans;
	
	lli aux = a[0].first;
	int pos = 0, cont = 0;
	for(int i = 1; i < n; i++) {
		if(aux != a[i].first) {
			pos = i;
			break;
		} else cont++;
	}

	for(int i = pos; i < n; i++) {
		ans.push_back(mk(a[0].second, a[i].second));
	}

	for(int i = 0; i < cont; i++) {
		ans.push_back(mk(a[pos].second, a[i+1].second));
	}
	if(ans.size() == n-1) {
		cout << "YES" << endl;
		fore(i, 0, ans.size()) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	} else cout << "NO" << endl;

}

int main() {
	int t; cin >> t;

	while(t--) solve();
}