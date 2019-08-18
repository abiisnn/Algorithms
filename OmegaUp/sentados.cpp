#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int fila, n_asiento, n_persona;
	int sentado, parado;
	cin >> fila >> n_asiento;
	cin >> n_persona;
	parado = 0;
	sentado = fila * n_asiento;
	if(n_persona > (fila * n_asiento))  parado = n_persona - (fila * n_asiento); 
	else if(n_persona < (fila * n_asiento)) sentado = n_persona;
	cout << sentado << " " <<parado;
	return 0;
}