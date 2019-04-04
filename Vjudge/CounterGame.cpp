#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

unsigned long long int nextPower(long long n) {
	unsigned int cont = 0;
	unsigned long long int next = n;
	while(n) {
		n = n >> 1;
		cont++;
	}
	next = next || (1 << cont);
	return next;
}
void counterGame(long long n) {
	int cont = 0;
	while(n > 1) {
		if(!(n & (n - 1))) 
			n /= 2;
		else 
			n -= nextPower(n); 
		cont ++;
	}
	if(cont & 1)
		cout << "Louise" << endl;
	else
		cout << "Richard" << endl;
}

int main(int argc, char const *argv[])
{
	int t, i;
	unsigned long long int n;
	cin >> t;
	for(i = 0; i < t; i++) {
		cin >> n;
		//cout << "Recibo: " << n << endl;
		if(n != 1)
			counterGame(n);
		else
			cout << "Richard" << endl;
	}
	return 0;
}
