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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> a(n), b(n);
	map<pair<lli, lli>, int> freq;
	fore(i, 0, n) cin >> a[i];
	fore(i, 0, n) cin >> b[i];
	int cont = 0;
	fore(i, 0, n) {
		if(!a[i] && !b[i]) { cont++; continue; }
		if(!a[i]) continue;
		lli gc = __gcd(a[i], b[i]);
		b[i] = -b[i];
		a[i] /= gc, b[i] /= gc;
		freq[mk(b[i], a[i])]++;
	}
	int best = 0;
	for(auto &i: freq) {
		if(i.se > best) best = i.se;
	}
	cout << best + cont << endl;
}