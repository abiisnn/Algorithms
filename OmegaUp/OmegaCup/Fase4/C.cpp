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
	int n; cin >>n;
	vector<ld> datos(n);
	fore(i, 0, n) {
		cin >> datos[i];
		datos[i] = log(datos[i]);
	}
	// VS:
	ld avg = 0, var = 0;
	fore(i, 0, n) avg += datos[i];
	avg = avg / n;
	// S:
	fore(i, 0, n) {
		var += ((datos[i] - avg) *(datos[i] - avg)); 
	}
	var = var / (n-1);	
	// M:
	ld des = sqrt(var);
	ld vs, s, m, l, vl;
	vs = (avg - (2 * des));
	s = (avg - des);
	m = (avg);
	l = (avg + des);
	vl = (avg + (2 *des));

	vs = exp(vs);
	s = exp(s);
	m = exp(m);
	l = exp(l);
	vl = exp(vl);
	cout << std::setprecision(2) << fixed;

	cout << vs << endl;
	cout << s << endl;
	cout << m << endl;
	cout << l << endl;
	cout << vl << endl;
}