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
	cout << primes[10000] << endl;
}