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
#define MAX 40000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> getDivs(lli n) {
	vector<lli> div;
	for(int i = 1ll; i * i <= n; i++) {
		if(!(n % i)) {
			div.push_back(i);
			if(i * i != n) div.push_back(n / i);
		}
	}
	return div;
}

bool isPrime(lli n) {
	bool prime = true;
	for(int i = 2; i <= sqrt(n); i++) {
		if((n % i) == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

void solve() {
	lli n; cin >> n;
	if(n == 1) {
		cout << "FastestFinger" << endl;
		return;
	} else if(n & 1) {
		cout << "Ashishgup" << endl;
		return;
	} else if(n == 2) {
		cout << "Ashishgup" << endl;
		return;
	}
	vector<lli> div = getDivs(n);
	bool allEven = true;
	for(int i = 0; i < div.size(); i++) {
		if(div[i] != 1 && (div[i] & 1)) {
			allEven = false;
			break;
		}
	}
	if(allEven) {
		cout << "FastestFinger" << endl;
		return;
	}

	if(div.size() >= 3 && (n % 4) == 0) {
		cout << "Ashishgup" << endl;
		return;
	}
	int cont = 0;
	while(n > 1 && (n % 2) == 0) {
		n /= 2ll;
		cont ++;
	}
	if(cont == 1 && isPrime(n)) cout << "FastestFinger" << endl;
	else cout << "Ashishgup" << endl;
}

int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}