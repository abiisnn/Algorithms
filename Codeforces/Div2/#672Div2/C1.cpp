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
#define MAX 300005
#define INI 1000000000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<vector<lli>> mem(MAX, vector<lli>(2, 0));
vector<vector<bool>> visited(MAX, vector<bool>(2, false));
vector<lli> a(MAX);

void clear() {
	fore(i, 0, MAX) mem[i][0] = mem[i][1] = 0;
	fore(i, 0, MAX) visited[i][0] = visited[i][1] = false;
}
lli dp(int n, int index, int time) {
	if(index >= n) return 0;
	if(visited[index][time & 1]) return mem[index][time & 1];	
	lli take = dp(n, index+1, time+1), noTake = dp(n, index+1, time);
	
	visited[index][time & 1] = true;
	mem[index][time & 1] = max(((time & 1) ? -a[index]: a[index]) + take, noTake);
	return mem[index][time & 1];
}
void solve() {
	int n, q; cin >> n >> q;
	fore(i, 0, n) cin >> a[i];
	clear();
	cout << dp(n, 0, 0) << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}