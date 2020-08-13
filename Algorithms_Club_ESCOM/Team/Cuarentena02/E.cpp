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
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	string s; cin >> s;

	int x = 0, y = 0;
	vector<pair<int, int>> p;
	p.pb(mk(0, 0));
	fore(i, 0, n) {
		if(s[i] == 'L') x--;
		else if(s[i] == 'R') x++;
		else if(s[i] == 'U') y++;
		else y--;
		p.pb(mk(x, y));
	}
	int start = 0, ans = 0;
	set<pair<int, int>> aux;
	fore(i, 0, p.size()) {
		while(aux.count(p[i])) {
			aux.erase(p[start]);
			start++;
		}
		aux.insert(p[i]);
		ans = max(ans, i - start);
	}
	cout << ans << endl;
}