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
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, r, val; cin >> n >> r;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];

	int index = -1, total = 0;
	bool flag = true;
	while(index < n-1) {
 		int heater = -1;
		for(int i = min(index+r, n-1); i > max(-1, index-r+1); i--) {
			if(v[i]) {
				heater = i;
				break;
			}
		}
		if(heater == -1) {
			flag = false;
			break;
		}
		total++;
		index = heater + r - 1;
	}
	if(flag) cout << total << endl;
	else cout << - 1 << endl;
}