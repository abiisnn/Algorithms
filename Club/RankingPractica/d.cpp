#include<bits/stdc++.h>

using namespace std;

long long cuentaImpar(vector<long long> v) {
	long long contador = 0;
	for(int i = 0; i < v.size(); i ++) {
		if(v[i] & 1)
			contador++;
	}
	return contador;
}
	
int main () {
	long long contador, tesoro, llave, aux;
	cin >> tesoro >> llave;
	vector <long long> l;
	vector <long long> t; 

	int isPar = 1;
	long long imparT = 0, parT = 0, imparL = 0, parL = 0;

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

	imparT = cuentaImpar(t);
	parT = t.size() - imparT;
	imparL = cuentaImpar(l);
	parL = l.size() - imparL;

	contador = min(imparT, parL);
	contador += min(imparL, parT);
	cout << contador << endl;
}
