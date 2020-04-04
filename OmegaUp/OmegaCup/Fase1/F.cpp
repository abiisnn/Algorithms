#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 500005
typedef long long int lli;

vector<lli> ans(MAX, 0);
vector<lli> p(MAX, 0), d(MAX, 0), r(MAX, 0); 
void dfs(lli i, lli &sec) {
	if(i == 0) return;
	sec = sec - d[i];
	if(sec >= 0){
		ans[p[i]]++;
		dfs(p[i], sec);
	} else return;
}
int main() {
	optimizar_io
	int n;
	lli a, b, c;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		p[i] = a, d[i] = b, r[i] = c;
	}
	for(int i = 1; i < n; i++) dfs(i, r[i]);
	fore(i, 0, n) cout << ans[i] << " ";
	cout << endl;
}