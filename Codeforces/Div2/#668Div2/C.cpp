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
	int n, k; cin >> n >> k;
	string s; cin >> s;

	bool flag = true;
	int ones = 0, zero = 0;
	for(int i = 0; i < k; i++) {
		int onesTem = 0, zerosTem = 0; 
		for(int j = i; j < n; j += k) {
			if(s[j] == '1') onesTem++;
			else if(s[j] == '0') zerosTem++;		
		}
		if(!onesTem && zerosTem) zero++;
		else if(onesTem && !zerosTem) ones++;
		else if(onesTem && zerosTem) {
			flag = false;
			break;
		}
	}
	if(max(ones, zero) > k/2) flag = false;
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}