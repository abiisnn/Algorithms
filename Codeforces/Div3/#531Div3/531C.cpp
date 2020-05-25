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

int main(int argc, char const *argv[]) {
	optimizar_io
	int n, x, y, aux;
	cin >> n >> x >> y;
	vector<int> v;
	int men = 0;
	fore(i, 0, n) {
		cin >> aux;
		if(aux <= x) {
			men++;
		} else v.pb(aux);
	}

	int ans = men / 2;
	if(men & 1) ans++;
	if(v.size() != 0 && (x > y)) ans++;
	if(x > y) ans = n;
	cout << ans << endl;
	return 0;
}