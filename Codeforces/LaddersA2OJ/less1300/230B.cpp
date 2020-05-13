#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<bool> isPrime;
void primesSieve(int n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]) {
			if(i <= limit)
				for(int j = i * i; j <= n; j += 2 * i)
					isPrime[j] = false;
		}
	}
}
int main() {
	optimizar_io
	int n; 
	cin >> n;
	primesSieve(MAX);
	vector<lli> numbers(n);
	fore(i, 0, n) cin >> numbers[i];
	fore(i, 0, n) {
		lli sq = sqrt(numbers[i]), aux = sq * sq;
		if((aux == numbers[i]) && isPrime[sq]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}