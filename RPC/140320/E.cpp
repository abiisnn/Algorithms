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
#define MAX 10000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<bool> isPrime;
vector<bool> ans;
void criba(int n) {
	isPrime.resize(MAX + 1, true);
	ans.resize(MAX + 1, false);
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

	ans[0] = ans[1] = ans[2] = true;

	limit = sqrt(MAX);
	for(int i = 2; i <= n; i++) {
		if(isPrime[i]) {
			for(int j = i, a = 1; j <= MAX; j = i * a, a++)
				ans[j] = true;
		}
	}
}

int main() {
	optimizar_io
	int n, k;
	cin >> n >> k;
	criba(n);
	
	int con = 1;
	for(int i = n+1; i < MAX; i++) {
		if(!(isPrime[i] or ans[i])) {
			if(con == k) {
				cout << i << endl;
				break;
			}
			con++;
		}
	}
}