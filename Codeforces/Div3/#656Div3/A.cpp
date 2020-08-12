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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	lli x, y, z;
	cin >> x >> y >> z;
	vector<lli> A = {x, y}, B = {x, z}, C = {y, z};
	lli a, b, c;
	bool flag = false;
	fore(i, 0, 2) {
		fore(j, 0, 2) {
			fore (k, 0, 2) {
				lli auxX = max(A[i], B[j]);
				lli auxY = max(A[i], C[k]);
				lli auxZ = max(B[j], C[k]);
				if(auxX == x && auxY == y && auxZ == z) {
					a = A[i], b = B[j], c = C[k];
					flag = true;
					break;
				}
			}
		}
	}
	if(flag) cout << "YES" << endl << a << " " << b << " " << c << endl;
	else cout << "NO" << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) {
		solve();
	}
}

/*
	x = 3
		a = 3 or b = 3
	y = 2
		a = 2 or c = 2
	z = 3
		b = 3 or c = 3
	
	a = x, b = z, c = y
	a = x, b = z, c = 

*/


