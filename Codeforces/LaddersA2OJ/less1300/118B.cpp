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
	optimizar_io
	int n;
	cin >> n;
	string second = "", numbers = "";
	vector<string> aux;
	fore(i, 0, n+1) {
		string ans((n-i)*2, ' ');
		numbers += char(i + '0');
		second = "";
		for(int j = numbers.size()-2; j >= 0; j--) second += numbers[j];
		string part = ans + numbers + second;
		aux.pb(part);
		numbers += ' ';
	}
	fore(i, 0, aux.size()) {
		fore(j, 0, aux[i].size()) cout << aux[i][j];
		cout << endl;
	}
	for(int i = aux.size()-2; i >= 0; i--) {
		fore(j, 0, aux[i].size()) cout << aux[i][j];
		if(i != 0) cout << endl;
	}

}