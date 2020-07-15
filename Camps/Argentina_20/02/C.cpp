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
#define MAX 100005
#define C 3
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, p; cin >> n >> p;
	string s; cin >> s;

	int equals = 0;
	fore(i, 0, n - p) {
		if(s[i] == s[i+p] && s[i] != '.') equals++;
		else if(s[i] == '.' && s[i+p] == '1') s[i] = '0';
		else if(s[i] == '.' && s[i+p] == '0') s[i] = '1';
		else if(s[i] == '1' && s[i+p] == '.') s[i+p] = '0';
		else if(s[i] == '0' && s[i+p] == '.') s[i+p] = '1';
		else if(s[i] == '.' && s[i+p] == '.') s[i] = '1', s[i+p] = '0';
	}
	fore(i, 0, n) {
		if(s[i] == '.') s[i] = '0';
	}
	if(equals == n-p) cout << "No" << endl;
	else cout << s << endl;
}