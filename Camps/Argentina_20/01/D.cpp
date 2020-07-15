#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 101
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	int n, one, two; cin >> n >> one >> two;
	vector<int> g(n);
	fore(i, 0, n) cin >> g[i];
	int ans = 0, twoAux = 0;
	fore(i, 0, n) {
		if(g[i] == 1) {
			if(one) one--;
			else if(two) {
				two--;
				twoAux++;
			} else if(twoAux) twoAux--;
			else ans++;
		} else {
			if(two) two--;
			else ans += 2;
		}
 	}
 	cout << ans << endl;
}