#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

vector<int> primes;
void linearPrimeSieve(int n) {	
	vector<bool> isPrime(n+1, true);
	for(int i = 2; i <= n; ++i) {
		if(isPrime[i]) {
			primes.push_back(i);
		}
		for(int p: primes) {
			int d = i * p;
			if(d > n) break;
			isPrime[d] = false;
			if(i % p == 0) break;
		}
	}
}
int main() {
	linearPrimeSieve(MAX);
	long long int n = 600851475143, greater = 0;
	while(n > 1) {
		for(int i = 0; i < primes.size(); i++) {
			if(n % primes[i] == 0) {
				cout << primes[i] << endl;
				if(primes[i] > greater) greater = primes[i];
				n /= primes[i];
				break;
			}
		}
	}
	cout << "Largest: " << greater << endl;
}