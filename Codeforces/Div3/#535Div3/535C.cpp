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

int check(string str, string pat, string &ans) {
	int iPat = 0, j = 0, dif = 0;
	while(j < str.size()) {
		if(pat[iPat] != str[j]) {
			dif++;
			ans[j] = pat[iPat]; 
		}
		iPat++;
		iPat %= pat.size();
		j++;
	}
	return dif;
}

int main() {
	vector<string> pattern = {"GRB", "GBR", "RGB", "RBG", "BRG", "BGR"};
	int n; 
	string str, auxString, ans;
	cin >> n >> str;
	int moves = 200005;
	fore(i, 0, pattern.size()) {
		auxString = str;
		int aux = check(str, pattern[i], auxString);
		if(aux < moves) {
			moves = aux;
			ans = auxString;
		}
	}
	cout << moves << endl;
	cout << ans << endl;
}