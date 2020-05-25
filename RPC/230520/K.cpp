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
ld eps = 1e-6;

int mod(int a, int b) { 
	return (b + (a % b)) % b; 
}
int main() {
	optimizar_io
	int n, m;
	cin >> n >> m;
	string plain, cipher;
	cin >> plain >> cipher;
	string aux(m-n, ' ');
	plain = aux + plain;
	string key(m, ' ');
	for(int i = m-1, j = m-n-1; i >= n; i--, j--) {
		int c = cipher[i] - 'a', a = plain[i]-'a';
		int d = c - a;
		int modulo = mod(d, 26);
		char charPlain = modulo +'a';
		plain[j] = charPlain;
	}
	cout << plain << endl;
}