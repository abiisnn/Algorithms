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
#define MAX 35
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		if((n/2)&1) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			lli dos = 0;
			for(lli i = 2; i < n+1; i+=2) {
				cout << i << " ";
				dos += i;
			}
			lli sum = 0;
			for(lli i = 1; i < n-1; i+=2) {
				cout << i << " ";
				sum += i;
			}
			cout << dos - sum << endl;
		}

	}
}