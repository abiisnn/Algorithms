#include <bits/stdc++.h>
using namespace std;
int main () {
	long long tesoro, llave, aux, suma, contador;
	cin >> tesoro >> llave;
	vector <long long> t; 
	vector <long long> l;

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
	for(int i = 0; i < l.size(); i++) {
		if(l[i] != -1) {
			for(int j = 0; j < t.size(); j++) {
				if(t[j] != -1) {			
					suma = l[i] + t[j];
					if(suma & 1) {
						l[i] = -1;
						t[j] = -1;					
						contador++;		
					}	
				} // if
				suma = 0;		
			} // for
		} // if
	} // for
	cout << contador << endl;
}
