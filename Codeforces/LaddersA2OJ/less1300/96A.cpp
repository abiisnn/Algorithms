#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	string str;
	cin >> str;

	int cont = 1, g = 0;
	fore(i, 0, str.size()-1) {
		if(str[i] == str[i+1]) cont++;
		else {
			if(cont > g) g = cont;
			cont = 1;
		}
	}
	if(cont > g) g = cont;
	if(g >= 7) cout << "YES" << endl;
	else cout << "NO" << endl;
}