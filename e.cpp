#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string cadena;
	cin >> cadena;
	long long contador = 0;
	long long respuesta = 0;
	for(int i = 0; i < cadena.size(); i++) {
		if(cadena[i] == '1')
			contador++;
	}
	respuesta = (contador * (contador + 1)) / 2;
	cout << respuesta;

	return 0;
}