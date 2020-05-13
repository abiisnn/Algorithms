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
	vector<lli> potencias(MAX);
	potencias[0] = 1;
	for(lli i = 1; i < MAX; i++) {
		potencias[i] = potencias[i-1] * 2;
	}
	int t;
	lli n;
	cin >> t;
	while(t--) {
		cin >> n;
		lli sum = 0, x = 0;
		fore(i, 0, MAX) {
			sum += potencias[i];
			if((n % sum) == 0 && i > 0) {
				x = n / sum;
				break;
			}
		}
		cout << x << endl;
	}
}