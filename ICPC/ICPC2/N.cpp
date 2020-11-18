#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 100005
#define MAXn 105
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

set<lli> priAns;
vector<lli> lp;
vector<int> primes;
vector<bool> isPrime;
void primesSieve(int n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]) {
			primes.push_back(i);
			if(i <= limit)
			for(int j = i * i; j <= n; j += 2 * i)
			isPrime[j] = false;
		}
	}
}
int lowestPrime(lli n, int &p) {
	int l = 0, r = primes.size() - 1;

	fore(i, 0, primes.size()) {
		if((n % primes[i]) == 0) {
			p = primes[i];
			return true;
		}
	}
	return false;
}
void factor(lli n) {
	map<lli, lli> f;
	while(n > 1) {
		int p;
		bool aux = lowestPrime(n, p);
		if(lowestPrime(n, p)) {
			int r = 0;
			while((n % p) == 0) {
				n /= p;
				r++;
			}
			f[p] = r;
			priAns.insert(p);
		}
	}
}

int main() {
	primesSieve(MAX);

	int M, N, K; cin >> M >> N >> K;

	vector<lli> C(N);
	fore(i, 0, N) cin >> C[i];

	fore(i, 0, K) {
		int m, n, times; cin >> m >>  n >> times;
	}
	fore(i, 0, N) factor(C[i]);

	for(auto &i: priAns) cout << i << " ";
	cout << endl;
}