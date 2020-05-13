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

int main() {
	optimizar_io
	int n, k;
	cin >> n >> k;
	vector<lli> v(n);
	fore(i, 0, n) cin >> v[i];
	fore(i, 1, n) v[i] = v[i-1] + v[i];
	
	int last = 0, pos = 0;
	lli minDif = 1000000000;
	for(int i = 0; i < n-k+1; i++) {
		lli dif = v[i+k-1];
		if(i) dif -= v[last];
		if(dif < minDif) {
			minDif = dif;
			pos = i + 1;
		}
		last = i;
	}
	cout << pos << endl;
}