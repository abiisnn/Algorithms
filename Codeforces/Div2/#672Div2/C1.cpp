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
#define MAX 300001
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<lli> odd(MAX), even(MAX);

void clear() {
	fore(i, 0, MAX) odd[i] = 0;
	fore(i, 0, MAX) even[i] = 0;
}
lli dp(int n, int index, int time) {
	if(index >= n) return 0;
	if(time & 1) {
		total -= a[index];
	} else {
		total += a[index];
	}
	lli take = total + dp(n, index + 1, time++);
	lli noTake = total 
}
void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	fore(i, 0, n) cin >> a[i];
	clear();
	cout << dp(n, 0, 0) << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}