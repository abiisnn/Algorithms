// https://atcoder.jp/contests/dp/tasks/dp_a
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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> DP(MAX, -1);

lli dp(vector<lli> &h, int i) {
	if(i == (h.size() - 1)) return 0;
	if(i > h.size()-1) return MAX;	
	if(DP[i] != -1) return DP[i];
	return DP[i] = min(dp(h, i+1) + abs(h[i] - h[i+1]), dp(h, i+2) + abs(h[i] - h[i+2]));
}

int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> h(n);
	fore(i, 0, n) cin >> h[i];
	cout << dp(h, 0) << endl;
}