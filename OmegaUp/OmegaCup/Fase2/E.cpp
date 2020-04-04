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

int main() {
	string str;
	cin >> str;
	int vocals = 0, letras = 0;
	fore(i, 0, str.size()) {
		char c = str[i];
		if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U' or c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
			vocals++;
		} else {
			letras++;
		}
	}	
	cout << str.size() << endl; 
	cout << vocals << endl;
	for(int i = str.size()-1; i >= 0; i--) {
		cout << str[i];
	} cout << endl;

}