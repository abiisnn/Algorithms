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

int main() {
	int n; cin >> n;
	vector<lli> d(n);

	fore(i, 0, n) cin >> d[i];
	sort(all(d));
	int l = 0, r = 0, best = 0, ans = 0;
	lli k = 5ll;
	while(l < n && r < n) {
		lli dif = abs(d[r] - d[l]);
		if(dif <= k) {
			ans = r - l + 1;
			r++;
		} else {
			if(ans > best) best = ans;
			l++;
			ans = r - l + 1;
		}
	}	
	if(ans > best) best = ans;
	cout << best << endl;
}