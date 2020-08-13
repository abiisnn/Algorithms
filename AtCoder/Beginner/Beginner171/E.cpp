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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> v(n);
	lli s = 0, ans;
	fore(i, 0, n) {
		cin >> v[i];
		s = s xor v[i];
	}
	fore(i, 0, n) {
		v[i] = s xor v[i];
		cout << v[i] << " ";
	} cout << endl;
	
	ans = 0;
	fore(i, 0, n) {
		fore(j, 0, n) {
			if(j != i) {
				ans = ans xor v[j];
			}
		}
		cout << ans << endl;
	}
}