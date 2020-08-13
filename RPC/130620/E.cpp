#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MOD 11092019
#define MAX 100000
typedef long long int lli;

vector<lli> pot(MAX);
lli mod(lli a, lli b) { return (b + (a % b)) % b; }
int main() {
	optimizar_io
	pot[0] = 1ll;
	pot[1] = 2ll;
	for(lli i = 2ll; i < 100; i++) {
		pot[i] = pot[i-1] * 2ll;
		pot[i] = mod(pot[i], MOD); 
	}
	fore(i, 0, 100) cout << pot[i] << " ";
	cout << endl;
	string str;
	cin >> str;
	map<char, int> bucket;
	fore(i, 0, str.size()) bucket[str[i]]++;
	int dif = bucket.size();
	lli ans = 0;
	int cont = 0;
	fore(i, 0, str.size()) {
		bucket[str[i]]--;
		int actual = bucket[str[i]];
		str[i]--;
		cont += actual;
	}
	cout << "contador: " << pot[cont] << endl;
	
	lli aux = pot[str.size()] - (pot[cont] * str.size());
	cout << "aux: " << aux << endl;
	cout << "no debe ser mayor a: " << pot[str.size()] << endl;
}