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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void printSol(lli n, int k) {
	for(int i = 0; i < k; i++) {
		cout << n << " ";
	}
	cout << endl;
}
bool isOdd(lli n) {
	if(n & 1) return true;
	return false;
}
void solve(lli n, int k) {
	// Try odd numbers
	lli con = n-k+1;
	if(isOdd(con) && con > 0) {
		cout << "YES" << endl;
		cout << con << " ";
		fore(i, 0, k-1) cout << "1 ";
		cout << endl;
	} else { // Try even numbers
		con = n - 2*(k-1);
		if(!isOdd(con) &&  con > 0) {
			cout << "YES" << endl;
			cout << con << " ";
			fore(i, 0, k-1) cout << "2 ";
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
int main() {
	optimizar_io
	lli n;
	int k, t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		solve(n, k);
	}
}