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
#define MOD 1000000007
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> F(46);
char findChar(lli fibo, lli pos) {
	if(fibo == 0) return 'a';
	if(fibo == 1) return 'b';

	lli middle = F[fibo] - F[fibo - 1] + 1;

	if(pos >= middle) return findChar(fibo - 1, pos - middle + 1);
	return findChar(fibo - 2, pos);
}	
void solve() {
	lli n, k; cin >> n >> k;
	cout << findChar(n, k) << endl;
}
int main() {
	optimizar_io
	F[0] = F[1] = 1ll;

	for(int i = 2; i < 46; i++) F[i] = F[i-2] + F[i-1];

	int t; cin >> t;
	while(t--) solve();
}