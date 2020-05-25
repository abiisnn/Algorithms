#include<bits/stdc++.h>
#define MAX 1000005
typedef long long int lli;
using namespace std;

int main() {
	int n, m, aux;
	cin >> n >>  m;
	vector<int> cosas;
	for(int i = 0; i < n; i++) {
		cin >> aux;
		if(aux < 0) { // Filtrar por lo que me puedo llevar
			cosas.push_back(aux);
		}
	}
	// -6 -4 -2
	sort(cosas.begin(), cosas.end());
	int total = 0;
	int fin = m; // originalmente fin = m porque quiero m cosas
	// pero puede pasar que tenga menos cosas de las que puedo comprar
	if(m > cosas.size()) fin = cosas.size(); 
	for(int i = 0; i < fin; i++) {
		total = total + cosas[i];
	}
	cout << -total << endl;
}