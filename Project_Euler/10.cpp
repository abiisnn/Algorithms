#include<bits/stdc++.h>
#define MAX 2500000
#define N 2000000
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
	long long int ans = 0;
	for(int i = 0; i < primes.size(); i++) {
		if(primes[i] < N) {
			ans += primes[i];
		} else break;
	}
	cout << ans << endl;
}