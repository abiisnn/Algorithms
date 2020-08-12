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

void solve() {
	int n;
	string s; cin >> n >> s;
	vector<int> ans(n);
	queue<int> zero, one;
	int total = 0;
	fore(i, 0, n) {
		if(s[i] == '0') {
			if(!one.empty()) {
				ans[i] = one.front();
				one.pop();
				zero.push(ans[i]);
			} else {
				total++;
				ans[i] = total;
				zero.push(total);
			}
		} else {
			if(!zero.empty()) {
				ans[i] = zero.front();
				zero.pop();
				one.push(ans[i]);
			} else {
				total++;
				ans[i] = total;
				one.push(total);
			}
		}
	}
	cout << total << endl;
	fore(i, 0, n) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while(t--) solve();
}