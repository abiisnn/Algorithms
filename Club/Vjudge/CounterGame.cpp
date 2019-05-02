#include <iostream>
#include <math.h>  
using namespace std;

typedef unsigned long long int ull;

ull nextPower(ull n) {
	ull cont = 0;
	ull next = n;
	ull num = 1;
	ull p = (ull)log(n) + 1;
	next = (ull)pow(2, p);
    cout << "Potencia menor es: " << next << endl;
	return next;
}
ull counter(ull n) {
	ull cont = (ull)log(n) + 1;
	cout << "cont: " << cont << endl;
	return cont;
}
void counterGame(ull n) {
	// cout << "Empiezo counterGame" << endl;
	ull cont = 0;
	while(n >= 1ll) {
		if(!(n & (n - 1ll))) {
			cout << "----------------> Encontre una potencia de dos" << endl;
			cout << "n es: " << n << endl;
			cont += counter(n);
			break;
		}
		else{
			cout << "-------------- > NO Soy potencia de dos" << endl;
			cout << "n es: " << n << endl;
			n -= nextPower(n);	
		}  
		cont ++;
	}
	cout << "Contador total: " << cont << endl;
	if(cont & 1)
		cout << "Louise" << endl;
	else
		cout << "Richard" << endl;
}

int main(int argc, char const *argv[])
{
	int t, i;
	ull n;
	cin >> t;
	for(i = 0; i < t; i++) {
		cin >> n;
		//cout << "Recibo: " << n << endl;
		if(n == 1ll)
			cout << "Richard" << endl;
		else
			counterGame(n);
	}
	return 0;
}
//18446744073709551615

//660570904136157 Richard