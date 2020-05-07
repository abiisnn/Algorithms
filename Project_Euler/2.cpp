#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int last = 2, fibo = 3, aux; 
	long long int ans = 2;
	while(fibo <= 4000000) {
		aux = fibo;
		fibo += last;
		last = aux;
		if(!(fibo & 1)) ans += fibo;
	}
	cout << ans;
}