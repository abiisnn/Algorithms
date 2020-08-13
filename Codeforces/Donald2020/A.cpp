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
#define MAX 26
#define INF 500000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	string s; cin >> s;
	map<char, char> m;
	m['O'] = '0';
	m['I'] = '1';
	m['Z'] = '2';
	m['E'] = '3';
	m['A'] = '4';
	m['S'] = '5';
	m['G'] = '6';
	m['T'] = '7';
	m['B'] = '8';

	m['o'] = '0';
	m['i'] = '1';
	m['z'] = '2';
	m['e'] = '3';
	m['a'] = '4';
	m['s'] = '5';
	m['g'] = '6';
	m['t'] = '7';
	m['b'] = '8';
	fore(i, 0, s.size()) {
		if(m.count(s[i])) {
			s[i] = m[s[i]];
		}
	}
	cout << s << endl;
}