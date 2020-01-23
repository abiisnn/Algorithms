// https://codeforces.com/contest/1294/problem/C
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000001
#define pb push_back
typedef long long int lli;
set<lli> noPrimes;
	
void primes(lli n) {
	//n++;
	noPrimes.insert(0); noPrimes.insert(1);
	for(lli i = 4; i <= n; i += 2) noPrimes.insert(i);
	lli limit = sqrt(n);
	
	for(lli i = 3; i <= n; i += 2) {
		if(noPrimes.count(i)) {
			if(i <= limit)
				for(int j = i * i; j <= n; j += 2 * i) noPrimes.insert(j);
		}
	}
}
map<lli, lli> factor(lli n) {
	map<lli, lli> f;
	while(n > 1) {
		if(noPrimes.count(n) == 1) {
			int p = 2;
			int r = 0;
			while((n % p) == 0) {
				n /= p;
				r++;
				f[p] = r;
				p++;
			}
		}
		else {
			f[n] = 1;
			break;
		}
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	map<lli, lli> factors;
	cin >> t;
	primes(MAX);

	cout << "-------------- SET" << endl;
	for(auto &i: noPrimes) {
		cout << i << " ";
	} cout << endl << endl << endl;

	factors = factor(t);
	cout << "-------------- MAP" << endl;
	for(auto &i: factors) {
		cout << i.first << " " << i.second << endl;
	}

}