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
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	int n, ele; cin >> n;
	int contOnes = 0, contZeros = 0;
	fore(i, 0, n) {
		cin >> ele;
		if(ele) contOnes++;
		else contZeros++;
	}

	if(contOnes <= n/2) {
		cout << n/2 << endl;
		fore(i, 0, n/2) cout << 0 << " ";
	} else {
		if(contOnes & 1) contOnes--;
		cout << contOnes << endl;
		fore(i, 0, contOnes) cout << 1 << " ";
	}
	cout << endl;
}

int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}

/*
	10
	odd = 1, even = 0
	delete odd

	0 1 1 1
	odd=1 even = 2

*/