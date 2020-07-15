#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 101
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	int t, n, num;
	cin >> t;
	while(t--) {
		cin >> n;
		int odd = 0, even = 0;
		fore(i, 0, n) {
			cin >> num;
			if(num & 1) odd++;
			else even++;
		}
		if((odd == 0) || ((even == 0) && (odd % 2 == 0))) cout << "NO" << endl;	
		else cout << "YES" << endl;
	}
}