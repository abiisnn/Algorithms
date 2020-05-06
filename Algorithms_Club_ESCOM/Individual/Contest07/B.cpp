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

lli mod(lli a, lli b) { 
	return (b + (a % b)) % b; 
}
void decipher(string str, lli s) {
	fore(i, 0, str.size()) {
		lli val = str[i];
		lli m = 26;
		if(str[i] >= 'A' && str[i] <= 'Z') {
			lli aux = val-'A'-s;
			val = mod(aux, m);
			val += 'A';B
		}
		else if(str[i] >= 'a' && str[i] <= 'z') {
			lli aux = val-'a'-s;
			val = mod(aux, m);
			val += 'a';
		}
		cout << char(val);
	}
}

int main() {
	optimizar_io
	int n; 
	lli s;
	string str;
	cin >> n >> s;
	cin.ignore();
	
	fore(i, 0, n) {
		getline(cin, str);
		decipher(str, s);
		if(i < n-1) cout << endl;
	}
}