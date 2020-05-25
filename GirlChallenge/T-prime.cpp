#include<bits/stdc++.h>
#define MAX 1000005
typedef long long int lli;
using namespace std;

vector<bool> isPrime;
void crearCriba(int n) {
	isPrime.resize(n+1, true);
	isPrime[0] = isPrime[1] = false;	
	// Ya sabemos que los multiplos de dos no son primos.
	for(int i = 4; i <= n; i+=2) isPrime[i] = false;
	for(int i = 3; i <= n; i++) {
		if(isPrime[i]) {
			for(int j = i+i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}
int main() {
	crearCriba(MAX);
	int n; cin >> n;
	vector<lli> numbers(n);
	for(int i = 0; i < n; i++) cin >> numbers[i];

	for(int i = 0; i < n; i++) {
		lli sq = sqrt(numbers[i]); 
		lli aux = sq * sq;
		if((aux == numbers[i]) && isPrime[sq]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}