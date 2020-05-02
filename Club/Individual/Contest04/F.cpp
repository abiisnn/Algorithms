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
#define MAX 105
#define MOD 1000000007 
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, m;
	cin >> n >> m;
	vector<int> C(n), A(n);
	fore(i, 0, n) cin >> A[i];
	fore(i, 0, m) cin >> C[i];

	int ans = 0, cost = 0, play = 0;
	while((cost < m) && (play < n)) {
		if(C[cost] >= A[play]) {
			cost++;
			ans++;
		}
		play++;
	}
	cout << ans << endl;
}