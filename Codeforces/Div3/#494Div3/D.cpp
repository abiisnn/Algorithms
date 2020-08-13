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
#define MAX 63
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
double eps = 1e-6;
vector<lli> a;
vector<int> pot(MAX);
vector<lli> pnum(MAX);

void freq(lli a) {
	for(int i = 0; i < sizeof(a)*8 - 1; i++) {
		if((a >> i) & 1) { pot[i]++; break; }
	}
}
lli min(lli a, lli b) {if(a < b) return a; return b;}
void solve() {
	lli b; cin >> b;
	int cont = 0;
	for(int i = MAX - 1; i >= 0; i--) {
		if(!b) break;
		int aux =  min(lli(b / pnum[i]), pot[i]);
		b -= (pnum[i] * aux);
		cont += aux;
	}
	if(cont && !b) cout << cont;
	else cout << -1;
	cout << endl;
}
int main() {
	optimizar_io
	int n, q; cin >> n >> q;
	a.resize(n);
	fore(i, 0, 63) pnum[i] = (1ll << i);

	fore(i, 0, n) {
		cin >> a[i];
		freq(a[i]);
	}
	while(q--) solve();
	
}