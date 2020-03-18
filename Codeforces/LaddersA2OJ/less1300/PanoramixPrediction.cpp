#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<bool> isPrime;
void criba() {
	isPrime.resize(MAX + 1, true);
	isPrime[0] = isPrime[1] = false;
	
	for(int i = 4; i <= MAX; i += 2) isPrime[i] = false;
	int limit = sqrt(MAX);
	for(int i = 3; i <= MAX; i += 2) {
		if(isPrime[i]) {
			if(i <= limit) {
				for(int j = i * i; j <= MAX; j += 2 * i) 
					isPrime[j] = false;
			}
		}
	}
}
int main() {
	optimizar_io
	int n, m;
	cin >> n >> m;
	criba();
	bool ans = false;
	n++;
	while(true) {
		if(isPrime[n]) {
			break;
		}
		n++;
	}
	if(n == m) cout << "YES" << endl;
	else cout << "NO" << endl;
}