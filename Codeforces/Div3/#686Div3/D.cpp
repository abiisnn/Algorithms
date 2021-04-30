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
#define MAX 1e5
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<bool> isPrime;
vector<int> primes;
void primesSieve(int n) {
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2) {
		if(isPrime[i]){
			primes.push_back(i);
			if(i <= limit)
				for(int j = i * i; j <= n; j += 2 * i) isPrime[j] = false;
		}
	}
}
vector<pair<lli, int>> factorize(lli n) {
	vector<pair<lli, int>> f;
	for(lli p : primes){
		if(p * p > n) break;
		int pot = 0;
		while(n % p == 0){
			pot++;
			n /= p;
		}
		if(pot) f.emplace_back(p, pot);
	}
	if(n > 1) f.emplace_back(n, 1);
	return f;
}

void solve() {
	lli num; cin >> num;
	vector<pair<lli, int>> fac = factorize(num);

	pair<lli, int> greater = {0, 0};
	for(auto &i: fac) {
		if(i.second > greater.second) {
			greater = i;
		}
	}

	if(greater.first == num) {
		cout << "1 " << endl << num << endl;
		return;
	}

	lli resi = num;
	int times = greater.second-1;
	cout << times + 1 << endl;
	while(times > 0) {
		cout << greater.first << " ";
		num /= greater.first;
		times--;
	}
	cout << num << endl;	
}
int main() {
	primesSieve(MAX);
	int t; cin >> t;
	while(t--) solve();
}