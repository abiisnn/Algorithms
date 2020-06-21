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

bool isPot2(lli n) {
	int cont = 0;
	for(int i = 0; i < sizeof(n) * 8; i++) {
		if((n >> i) & 1) cont++;
	}
	if(!(cont-1)) return true;
	return false;
}


int main() {
	optimizar_io
	int t; cin >> t;
	lli n;
	while(t--) {
		cin >> n;
		if(n <= 2 or isPot2(n)) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}