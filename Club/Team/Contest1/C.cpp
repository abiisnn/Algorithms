#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define pairs pair<lli, lli>
#define fi first
#define se second
#define endl '\n'
#define N 3
typedef long long int lli;

int main() {
	optimizar_io
	int p;
	cin >> p; 

	// Calculate all squares:
	map<lli, lli> m;
	lli aux = 0;
	for(lli i = 1; i < p; i++) {
		aux = i;
		aux *= aux; 
		aux %= p; 
		m[aux] = i;
	}
	cout << "0 ";
	fore(i, 1, p) {
		if(m[i]) {
			cout << m[i]<< " ";
		} else {
			cout << "-1 "; 
		}
	}	
	cout << endl;

}	