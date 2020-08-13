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
#define MAX 1000000000000000000
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
	lli a;
	string b, fi = "";
	cin >> a >> b;

	int i = 0;
	while(b[i] != '.') fi += b[i], i++;
	
	string sec = b.substr(i+1, 2);
	int B = convert(fi);
	int dec = convert(sec);
	lli ans = a * B + ((a * dec) / 100ll);
	cout << ans << endl;
}