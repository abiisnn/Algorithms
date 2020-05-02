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
	string a, b;
	cin >> a >> b;
	int ia = 0, ib = 0;
	while(ia < a.size() && ib < b.size()) {
		if(a[ia] == b[ib]) {
			cout << ia << " " << ib << endl;
			ia++; ib++;
		} else ia++;
	}
	
}