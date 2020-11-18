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

void getDivs(vector<int> &div, int num) {
	for(int i = 1; i * i <= num; i++) {
		if(!(num % i)) {
			div.pb(i);
			if(i * i != num) div.pb(num/ i);
		}
	}
}
void solve() {
	int n, x, y; cin >> n >> x >> y;
	vector<int> div, ans(n), bestAns(n);
	getDivs(div, y-x);
	// sort(all(div));
	int bestMax = INT_MAX; 
	for(int i = 0; i < div.size(); i++) { // Try with div[i]
		ans[0] = y;
		// Fill serie with div[i]
		for(int j = 1; j < n; j++) {
			ans[j] = ans[j-1] - div[i];
		}
		// Correct vector and doesnt have negative numbers
		int times = 1, maxhere = y, minhere = INT_MAX;
		for(int j = 0; j < n; j++) {
			if(ans[j] <= 0) {
				ans[j] = y + (times * div[i]);
				times++;
				maxhere = ans[j];
			}
			minhere = min(minhere, ans[j]);
		}
		// Check that x exist && ans[i] > 0
		if(maxhere < bestMax && minhere <= x) {
			bestMax = maxhere;
			bestAns = ans;
		}
	}
	for(int i = 0; i < n; i++) cout << bestAns[i] << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while(t--) solve();
}