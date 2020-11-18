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

vector<int> helper(7, 0);
void solve() {
	int x; cin >> x;

	int dig = x % 10;
	int ans = (dig-1) * 10;

	int cont = 0;
	while(x) {
		x/=10;
		cont++;
	}
	ans += helper[cont];
	cout << ans << endl;

}

int main() {
	optimizar_io
	int t; cin >> t;
	for(int i =1; i < 7; i++) {
		helper[i] = helper[i-1] + i; 
	}
	while(t--) solve();
}