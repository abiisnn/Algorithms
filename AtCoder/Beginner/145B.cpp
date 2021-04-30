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

int main() {
	optimizar_io
	int n; cin >> n;
	string s; cin >> s;

	bool is = true;
	if(n & 1) is = false;
	else {
		for(int i = 0, j = n/2; i < n/2; i++, j++) {
			if(s[i] != s[j]) {
				is = false;
				break;
			}
		}		
	}
	if(is) cout << "Yes" << endl;
	else cout << "No" << endl;
}