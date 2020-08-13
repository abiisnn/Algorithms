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
	optimizar_io
	int a, b, x; cin >> a >> b >> x;
	string ans = "", pattern = "10";
	int cont = 0, zero = 0, ones = 0;
	int i = 1;
	if(b > a) i = 0;
	while(cont < x+1) {
		ans += pattern[i];
		if(pattern[i] == '1') ones++;
		else zero++;
		i++;
		i %= 2;
		cont++;
	}
	a -= zero; b -= ones;
	fore(i, 0, ans.size()) {
		cout << ans[i];
		if(ans[i] == '0') while(a > 0) cout << 0, a--;
		if(ans[i] == '1') while(b > 0) cout << 1, b--;
	}
	
}