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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
void solve(int n, int k, vector<int>&a, vector<int>&b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	lli ans = 0;
	int movs = 0;
	for(int i = 0, j = b.size()-1; i < a.size(); i++) {
		int choose = a[i];
		if(movs < k) {
			if(b[j] > a[i]) {
				choose = b[j];
				movs++;
				j--;
			}
		}
		ans += choose;
	}
	cout << ans << endl;
}

int main() {
	optimizar_io
	int t;
	int n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		vector<int> a(n), b(n);
		fore(i, 0, n) cin >> a[i];
		fore(i, 0, n) cin >> b[i];
		solve(n, k, a, b);
	}
	
}