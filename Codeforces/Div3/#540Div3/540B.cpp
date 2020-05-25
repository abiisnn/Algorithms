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
	int n; cin >> n;
	vector<int> v(n);
	vector<lli> acum(n);
	fore(i, 0, n) cin >> v[i];

	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	acum[n-2] = v[n-2];
	for(int i = n-4; i >= 0; i-=2) {
		acum[i] = v[i] + acum[i+2];
	}
	acum[n-1] = v[n-1];
	for(int i = n-3; i >= 0; i-=2) {
		acum[i] = v[i] + acum[i+2];
	}
	acum.pb(0); acum.pb(0);
	lli acumOne = 0, acumTwo = 0;
	int cont = 0;
	for(int i = 0; i < n; i++) {
		lli sumO = acumOne + acum[i+1], sumT = acumTwo + acum[i+2];
		if(i & 1) {
			sumO = acumOne + acum[i+2];
			sumT = acumTwo + acum[i+1];
		}
		if(sumT == sumO) cont++;
		if(i & 1) acumTwo += v[i];
		else acumOne += v[i];
	}
	cout << cont << endl;
}