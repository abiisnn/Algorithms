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
#define MAX 110
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int lowerBound(vector<int> &v, int target) {
	int l = 0, r = v.size() - 1;
	while(l <= r) {
		int m = l + (r - l) / 2;
		if(v[m] < target) l = m + 1;
		else if(v[m] > target) r = m - 1;
		else r = m - 1;
	}
	return l;
}
int main() {
	int n, num, a; cin >> num >> n;
	set<int> is;
	fore(i, 0, n) {
		cin >> a;
		is.insert(a);
	}
	vector<int> v;
	fori(i, 0, MAX) {
		if(!is.count(i)) v.pb(i);
	}
	int ind = lowerBound(v, num), size = v.size();
	int best = 10000, ans, ini = std::max(0, ind-5), end = std::min(size, ind+5);
	fore(i, ini, end) {
		int dif = abs(v[i] - num);
		if(dif < best) {
			best = dif;
			ans = v[i];
		}
	}
	cout << ans << endl;
}
