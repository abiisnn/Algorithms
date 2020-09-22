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

vector<lli> elem(MAX);
void solve() {
	lli x; cin >> x;
	lli sum = 0, cont = 0;
	fore(i, 0, MAX) {
		if(sum + elem[i] <= x) {
			sum += elem[i];
			cont++;
		} else break;
	}
	cout << cont << endl;
}
lli formula(lli x) {
	return (x * (x + 1)) / 2ll;
}
int main() {
	int t; cin >> t;
	lli x = 1, two = 1ll;
	for(int i = 0; i < MAX; i++) {
		elem[i] = formula(x);
		two *= 2;
		x += two;
	}
	while(t--) solve();
}