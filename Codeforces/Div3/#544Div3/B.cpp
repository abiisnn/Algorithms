#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
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

lli min(lli a, lli b) {
	if(a < b) return a;
	return b;
}
int main() {
	optimizar_io
	int n, k; cin >> n >> k;
	vector<lli> d(n);
	map<lli, int> bucket;
	int ans = 0;
	fore(i, 0, n) {
		cin >> d[i];
		d[i] = d[i] % k;
		if(d[i]) bucket[d[i]]++;
		else ans++;
	}
	map<lli, bool> visited;
	for(auto &i: bucket) {
		visited[i.fi] = false;
	}

	for(auto &i: bucket) {		
		lli need = k - i.fi;
		lli add;
		if(visited[need] or visited[i.fi]) continue;
		visited[need] = true;
		visited[i.fi] = true;
		if(need == i.fi) {
			add = 2 * int(i.se / 2);
			i.se -= add;
		} else {
			lli actual = bucket[need];
			add =  (2 * min(i.se, actual));
			i.se -= min(i.se, actual);
			bucket[need] = actual - min(i.se, actual);
		}
		ans += add;
	}
	if(ans & 1) ans--;
	cout << ans << endl;


}