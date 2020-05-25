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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> v(n);
		map<int, int> buck;
		int even = 0, odd = 0;
		fore(i, 0, n) {
			cin >> v[i];
			if(v[i] & 1) odd++;
			else even++;
			buck[v[i]]++;
		}
		if(!(even & 1) && !(odd & 1)) {
			cout << "YES" << endl;
		} else if((even == n) or (odd == n)) {
			cout << "YES" << endl;
		} else {
			bool flag = false;
			for(auto &i: buck) {
				int aux = buck.count(i.fi+1), aux2 = buck.count(i.fi-1);
				if(aux or aux2) {
					flag = true;
					break;
				}
			}
			if(flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}