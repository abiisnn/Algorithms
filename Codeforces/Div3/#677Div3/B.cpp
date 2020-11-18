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
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];
	int pos = -1;
	fore(i, 0, n) {
		if(v[i]) {
			pos = i;
			break; 
		}
	}
	int last = -1;
	for(int i = n-1; i >= 0; i--) {
		if(v[i]) {
			last = i;
			break;
		}
	}

	if((last == -1 && pos == -1) || (last == pos)) {
		cout << 0 << endl;
		return;
	}
	int cont = 0;
	for(int i = pos; i <= last; i++) {
		if(!v[i]) cont++;
	}
	cout << cont << endl;

}

int main() {
	optimizar_io
	int t; cin >> t;

	while(t--) solve();
}