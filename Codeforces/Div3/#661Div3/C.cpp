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
#define MAX 1000000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int check(map<int, int> &bucket, int n) {
	int ans = 0;
	fore(i, 1, n/2 + 1) {
		int aux1 = bucket[i];
		int aux2 = bucket[n-i];
		if(i == n-i) ans += (aux1 / 2);
		else ans += min(aux1, aux2);
	}
	return ans;
}
void solve() {
	int n; cin >> n;
	vector<int> v(n);
	map<int, int> bucket;
	fore(i, 0, n) {
		cin >> v[i];
		bucket[v[i]]++;
	}
	sort(v.begin(), v.end());

	if(v.size() == 1) {
		cout << 0 << endl;
		return;
	}
	int minS = v[0] + v[1];
	int maxs = v[v.size()-1] + v[v.size()-2];

	int ans = 0;
	fori(i, minS, maxs) {
		ans = std::max(check(bucket, i), ans);
	} 
	cout << ans << endl;
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}