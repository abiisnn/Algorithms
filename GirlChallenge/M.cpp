#include<bits/stdc++.h>
#define MAX 1000005
typedef long long int lli;
using namespace std;

vector<bool> isPrime;
// Criba de primos
void createPrimes(int n) {
	isPrime.resize(n+1, true);
	isPrime[0] = isPrime[1] = false;
	// 2, 3
	// multiplos del 2, y todos +2, no son primos, 4, 6, 8, 10
	for(int i = 4; i <= n; i+=2) {
		isPrime[i] = false;
	}
	// Criba
	for(int i = 3; i <= n; i++) {
		if(isPrime[i]) {
			for(int j = i+i; j <= n; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}
int main() {
	createPrimes(MAX);
	
}