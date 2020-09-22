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
#define MAX 31
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	vector<int> v(n), ans(n);
	fore(i, 0, n) cin >> v[i];
	sort(all(v));
	int j = 0;
	for(int i = 1; i < n; i+=2, j++) {
		ans[i] = v[j];
	}
	for(int i = 0; i < n; i+=2, j++) {
		ans[i] = v[j];
	}
	int cont = 0;
	fore(i, 1, n-1) {
		if(ans[i] < ans[i-1] && ans[i] < ans[i+1]) cont++;
	}
	cout << cont << endl;
	fore(i, 0, n) cout << ans[i] << " ";
	cout << endl;
}