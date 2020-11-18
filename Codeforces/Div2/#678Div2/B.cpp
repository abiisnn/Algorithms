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
#define MAX 100000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<int> primes;
vector<bool> isPrime;
void primesSieve(int n) {
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]) {
			primes.push_back(i);
			if(i <= limit)
				for(int j = i * i; j <= n; j += 2 * i) isPrime[j] = false;
		}
	}
}
int best(int sum) {
	vector<int>::iterator up = upper_bound(all(primes), sum);
	int pos = *up, lastRow = 0;
	for(int i = pos+1; i < min((int)primes.size(), pos + 10); i++) {
		int need = primes[i] - sum;
		if(!isPrime[need] && need <= 100000) {
			lastRow = need;
			break;			
		}
	}
	return lastRow;
}
void solve() {
	int n; cin >> n;
	if(n == 2) {
		cout << "1 1" << endl;
		cout << "1 1" << endl;
		return;	
	}
	vector<vector<int>> matrix(n, vector<int>(n, 0));

	fore(i, 0, n) matrix[n-1][i] = matrix[n-2][i] = 1;
	fore(i, 0, n) matrix[i][n-1] = matrix[i][n-2] = 1;
	
	matrix[n-1][n-1] = best(2* (n-1));
	matrix[n-1][n-2] = matrix[n-2][n-1] = best(n-1);
	matrix[n-1][n-1] = best((n-2) + matrix[n-2][n-1]);

	fore(i, 0, n) {
		fore(j, 0, n) cout << matrix[i][j] << " ";
		cout << endl;
	}
}

int main() {
	optimizar_io

	primesSieve(MAX);
	int t; cin >> t;
	while(t--) solve();
}