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
#define MAX 105
typedef long long int lli;

int main() {
	optimizar_io
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<lli> team(n, 0);
		lli gcdTeam = 0;
		fore(i, 0, n) {
			cin >> team[i];
			gcdTeam = __gcd(gcdTeam, team[i]);
		}
		lli ans = 0;
		fore(i, 0, n) {
			ans += (team[i] / gcdTeam);
		}
		cout << gcdTeam << " " << ans << endl;
	}
}