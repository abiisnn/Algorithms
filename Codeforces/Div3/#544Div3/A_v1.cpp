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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int convert(string s) {
	int i; 
	istringstream(s) >> i;
	return i;
}

int main() {
	optimizar_io
	string a, b;
	cin >> a >> b;

	int h1 = convert(a.substr(0, 2));
	int m1 = convert(a.substr(3, 2));
	int h2 = convert(b.substr(0, 2));
	int m2 = convert(b.substr(3, 2));

	int min = (((h2 - h1) * 60) + m2 - m1) / 2;
	int minAux = (h1 * 60) + m1 + min;
	
	int h3 = minAux / 60;
	int m3 = minAux % 60;
	if(h3 >= 0 && h3 <= 9) cout << 0;
	cout << h3 << ":";
	if(m3 >= 0 && m3 <= 9) cout << 0;
	cout << m3 << endl;
}