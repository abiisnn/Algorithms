#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 20000000
#define MOD 1000000007
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	lli h, w, a, b; cin >> h >> w >> a >> b;

	vector<lli> two(MAX);
	two[0] = 1;
	fore(i, 1, MAX) {
		two[i] = (two[i-1] * 2ll) % MOD;
	}
	cout << two[42] << endl;
}