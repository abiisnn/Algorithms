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

void solve() {
	int n;
	string s;
	cin >> n >> s;
	bool inc = true;
	fore(i, 0, n-1) {
		if(s[i+1] < s[i]) {inc = false; break;}
	}
	if(inc) {cout << s << endl; return;}
	int i = 0, zeros = 0, ones = 0;
	while(s[i] != '1') {zeros++; i++;}
	i = n - 1;
	while(s[i] != '0') {ones++; i--;}
	string a(zeros+1, '0'), b(ones, '1');
	cout << a + b << endl;
}
int main() {
	optimizar_io
	int t, n; cin >> t;
	string s;
	while(t--) {
		solve();
	}
}