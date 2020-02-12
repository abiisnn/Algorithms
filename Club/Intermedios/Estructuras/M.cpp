// https://vjudge.net/contest/353813#problem/M
// https://codeforces.com/contest/602/problem/B
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define endl '\n'
#define logMAX 20
#define NMAX 100005
typedef long long int lli;

int minN[NMAX][logMAX];
int maxN[NMAX][logMAX];

int fmin(int a, int b) {
	int ans;
	if(a < b) ans = a;
	else ans = b;
	return ans;
}
int fmax(int a, int b) {
	int ans;
	if(a > b) ans = a;
	else ans = b;
	return ans;
}
void sparseTable(vector<int> &n) {
	fore(i, 0, n.size())
		minN[i][0] = n[i];

	for(int j = 1; (1 << j) <= n.size(); j++) {
		for(lli i = 0; (i + (1 << j)) <= n.size(); i++) {
			minN[i][j] = fmin(minN[i][j - 1], minN[i + (1 << (j - 1))][j - 1]);
		}
	}
	fore(i, 0, n.size())
		maxN[i][0] = n[i];

	for(int j = 1; (1 << j) <= n.size(); j++) {
		for(lli i = 0; (i + (1 << j)) <= n.size(); i++) {
			maxN[i][j] = fmax(maxN[i][j - 1], maxN[i + (1 << (j - 1))][j - 1]);
		}
	}
}
pair<int, int> query(int l, int r) {
	int j = (int)log2(r - l + 1);
	pair<int, int> ans;
	ans.first = minN[r - (1 << j) + 1][j];
	ans.second = maxN[r - (1 << j) + 1][j];
	
	if(minN[l][j] < ans.first) ans.first = minN[l][j];
	if(maxN[l][j] > ans.second) ans.second = maxN[l][j];
	return ans;
}
int main() {
	int n, a, l, r;
	cin >> n;
	vector<int> num(n, 0);
	vector<int> ans;
	pair<int, int> mm;
	fore(i, 0, n) cin >> num[i];
	sparseTable(num);

	l = 0, r = 0;
	while((l < n) && (r < n)) {
		mm = query(l, r);
		if((mm.second - mm.first) <= 1) {	
			ans.pb(r - l + 1);
			r++;
		}
		else l++;
	}	
	ans.pb(0);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << endl;
} 