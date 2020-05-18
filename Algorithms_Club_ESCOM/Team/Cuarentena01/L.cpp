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
#define MAX 1005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int t, n, num; 
	cin >> t;
	while(t--) {
		cin >> n;
		set<int> ganadores;
		// Generar ganadores:
		int cada = (n-1) * (n-1);
		for(int i = n; i <= MAX; i += cada+(n-1)) {
			for(int j = i; j < i+cada; j++) {
				ganadores.insert(j);
			}
		}
		string ans = "Bob";
		fore(i, 0, n) {
			cin >> num;
			if(ganadores.count(num)) {
				ans = "Alice";
			}
		}
		cout << ans << endl;
	}
}