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
#define MAX 105
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
	lli d;
	vector<int> bucket(MAX, 0);
	int ans = 0;
	fore(i, 0, n) {
		cin >> d;
		d %= k;
		if(d) bucket[d]++;
		else ans++;
	}
	fori(i, 0, k/2) {
		if(bucket[i]) {
			int need = k - i;
			if(need == i) ans += (2 * int(bucket[i] / 2));
			else ans += 2 * min(bucket[i], bucket[need]);
		}
	}
	if(ans & 1) ans--;
	cout << ans << endl;
}