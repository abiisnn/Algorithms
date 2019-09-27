#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
// Cuenta divisores
int countDiv(int a) {
	int cont = 0;
	for(int i = 1; i*i < a; i++) {
		if((a % i == 0)) {
			if((a/i)!= i) cont += 2;
			else cont++;
		}
	}
	return cont;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc, n;
	cin >> tc;
	for (int i = 1; i <= tc; i++){
		cin >> n;
		if(n == 1 or n == 2) cout << "0" << endl;
		else {
			int divs = countDiv(n);
			if (n & 1) n--;
			cout << "Case # " << tc << ": " << n - divs << endl;
		} 
	}
}