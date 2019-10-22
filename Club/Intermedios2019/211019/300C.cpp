#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, n;
	long long int numero;
	cin >> a >> b >> n;
	// Generate GOOD:
	for(int i = 0, j = n; i <= n; i++, j--) {
		numero = (i * a) + (j * b);
		cout << numero << endl;
	}

	
}