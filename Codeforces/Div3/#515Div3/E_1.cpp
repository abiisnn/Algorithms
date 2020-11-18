#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 200000
#define MOD 998244353
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, m;
	string a, b;
	cin >> n >> m >> a >> b;

	// Precalculo
	vector<lli> potencias(MAX);
	potencias[MAX - 1] = 1;
	for(int i = MAX - 2; i >= 0; i--) {
		potencias[i] = (potencias[i + 1] * 2ll) % MOD;
	}
	// Acumulado para saber cuantas veces pasa un uno de b, enn un uno de A
	vector<int> acum(MAX);
	int indexAcum = MAX - b.size();
	int ones = 0;
	for(int i = 0; i < (int)b.size(); i++) {
		if(b[i] == '1') ones++;
		acum[indexAcum] = ones;
		indexAcum++;
	}
	// Con el acumulado, sacar la respuesta
	indexAcum = MAX - a.size();
	lli total = 0;
	for(int i = 0; i < (int)a.size(); i++) {
		if(a[i] == '1') {
			total =  (total + (acum[indexAcum] * potencias[indexAcum]) % MOD) % MOD; 			
		}
		indexAcum++;
	}
	cout << total << endl;
}