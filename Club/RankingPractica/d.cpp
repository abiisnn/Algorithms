#include <bits/stdc++.h>
using namespace std;

long long cuentaImpar(vector<long long> v) {
	long long contador = 0;
	for(int i = 0; i < v.size; i ++) {
		if(v[i] && 1 && (v[i] != -1))
			contador++;
	}
	return contador;
}
long long cuentaPar(vector<long long> v) {
	long long contador = 0;
	for(int i = 0; i < v.size; i ++) {
		if(!(v[i] && 1) && (v[i] != -1))
			contador++;
	}
	return contador;
}

vector <long long> t; 
	
int main () {
	long long contador, tesoro, llave, aux;
	cin >> tesoro >> llave;
	vector <long long> l;
	int isPar = 1;
	long long impar = 0, par = 0;

	// Recibir datos
	for(int i = 0; i < tesoro; i++) {
		cin >> aux;
		t.push_back(aux);
	}
	for(int j = 0; j < llave; j++) {
		cin >> aux;
		l.push_back(aux);
	}

	contador = 0;
	for(int i = 0 ; i < l.size(); i ++) {
		if(l[i] && 1) {
			impar = cuentaImpar(t);

		}
		impar = cuentaImpar(t);
		par = cuentaPar(t);
	}
	cout << contador << endl;
}
