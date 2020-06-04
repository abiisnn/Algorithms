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
void printBits(int n) {
	for (int i = sizeof(n) * 8 - 1; ~i; i--)
		cout << ((n >> i) & 1);
	cout << endl;
}
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> v(n);
		set<int> real;
		fore(i, 0, n) {
			cin >> v[i];
			real.insert(v[i]);
		}
		int ans = 0;
		fori(i, 1, 1024) {
			set<int> aux;
			fore(j, 0, n) {
				aux.insert(v[j] xor i);
			}
			if(aux == real) {
				ans = i;
				break;
			}
		}
		if(ans) cout << ans << endl;
		else cout << -1 << endl;
	}
}