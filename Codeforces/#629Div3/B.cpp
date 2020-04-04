#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define endl '\n'

typedef long long int lli;

lli gauss(lli n) {
	return (n * (n-1)) / 2;
}

lli findPos(lli n, lli target) {
	lli l = 1, r = n;
	lli ans = 0;
	while(l <= r) {
		lli mid = l + (r - l) / 2;
		if(gauss(mid) + 1 <= target) {
			ans = mid;
			l  = mid + 1;
		} else r = mid - 1;
	}
	return ans;
}

int main() {
	optimizar_io
	int t, n;
	lli k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		lli pos = findPos(n, k);
		lli pos2 = k - gauss(pos)-1;
		// cout << "pos: " << pos << endl;
		// cout << "pos2: " << pos2 << endl;
		// cout << "gauus: " << gauss(pos)<< endl;
		string ans = "";
		for(int i = 0; i < n; i++) {
			ans += 'a';
		}
		ans[n-1-pos] = 'b';
		ans[n-1-pos2] = 'b';
		cout << ans << endl;
	}

}