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
	int x, y; cin >> x >> y;
	bool flag = false;
	fore(i, 0, 200) {
		fore(j, 0, 200) {
			if(((2*i + 4*j) == y) && (i + j == x)) {
				flag = true;
				break;
			} 
		}
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}
