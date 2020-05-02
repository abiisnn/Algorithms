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
#define MAX 105
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
bool geq(ld a, ld b){return a-b >= -eps;}
// bool ge(dato a, dato b){return a-b > eps;}
// bool le(dato a, dato b){return b-a > eps;}
// bool leq(dato a, dato b){return b-a >= -eps;}
// bool eq(dato a, dato b){return abs(a-b) <= eps;}

vector<ld> mem(MAX, -1);
vector<bool> visitados(MAX, false);
ld dp(vector<ld> &datos, int i) {
	if(visitados[i]) return mem[i];
	if(i == datos.size()-1) return datos[i];
	visitados[i] = true;
	ld maxSum = 0;
	for(int j = i+2; j < datos.size(); j++) {
		ld aux = dp(datos, j);
		if(aux > maxSum) maxSum = aux;
	}
	return mem[i] = datos[i] + maxSum;
}

int main() {
	optimizar_io
	int n; cin >> n;
	vector<ld> datos(n);
	fore(i, 0, n) cin >> datos[i];
	
	ld maxSum = 0;
	std::cout << std::setprecision(1);
  	std::cout << std::fixed;
	fore(i, 0, n) {
		ld dpAqui = dp(datos, i);
		if(geq(dpAqui, maxSum)) maxSum = dpAqui;
		// cout << "dp en " << i << " es: " << dpAqui << endl;
	}
	cout << maxSum << endl;
}