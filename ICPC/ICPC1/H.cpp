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
#define MAX 55
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<int> dp(MAX, -1), c(MAX);
void clear() {
	fore(i, 0, MAX) dp[i] = -1;
}
int calcule(int i, int n) {
	if(i >= n) return -1;
	if(dp[i] != -1) return dp[i];

	int aux = calcule(i+2, n);
	int take = c[i];
	if(aux != -1) take += aux;
	int noTake = calcule(i+1, n);
	
	return dp[i] = max(take, noTake);
}
void solve() {
	clear();
	int n; cin >> n;
	fore(i, 0, n) cin >> c[i];
	cout << calcule(0, n) << endl;
}

int main() {
	optimizar_io
	int t; cin >> t;

	while(t--) solve();
}