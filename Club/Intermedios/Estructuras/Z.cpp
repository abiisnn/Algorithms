// https://vjudge.net/contest/353813#problem/Z
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define logMAX 8
#define NMAX 10000005
typedef long long int lli;

int dp[NMAX][logMAX];

int f(int a, int b) {
	int ans;
	if(a > b) ans = a;
	else ans = b;
	return ans;
}
void sparseTable(vector<int> &n) {
	fore(i, 0, n.size())
		dp[i][0] = n[i];

	for(int j = 1; (1 << j) <= n.size(); j++) {
		for(int i = 0; (i + (1 << j) - 1) < n.size(); i++) {
			dp[i][j] = f(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int query(int l, int r) {
	int j = (int)log2(r - l + 1);
	int ans = dp[r - (1 << j) + 1][j];
	if(dp[l][j] > ans) ans = dp[l][j];
	return ans;
}
int main() {
	optimizar_io
	int n, k, j;
	cin >> n;
	vector<int> num(n, 0);
	fore(i, 0, n) cin >> num[i];
	cin >> k;
	// Sparse Table:
	sparseTable(num);
	j = k - 1;
	for(int i = 0; i <= n - k; i++) {
		cout << query(i, j) << " ";
		j++;
	}
	cout << endl;
}