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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];

	set<int> aux;
	vector<int> ans(n);
	for(int i = n-1; i >= 0; i--) {
		aux.insert(v[i]);
		ans[i] = aux.size();
	}
	fore(i, 0, m) {
		cin >> n;
		cout << ans[n-1] << endl;
	}
}