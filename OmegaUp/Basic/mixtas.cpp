#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	int entero, residuo;
	cin >> n >> m;
	if((n % m) != 0) {
		entero = n/m; 
		residuo = n - (m * entero);
		cout << entero << " " << residuo << "/" << m;
	}
	else
		cout << n/m ;
	return 0;
}