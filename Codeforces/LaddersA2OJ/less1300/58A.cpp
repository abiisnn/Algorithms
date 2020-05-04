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
	string pattern = "hello";

	int i = 0, p = 0, cont = 0;
	while(i < str.size() && p < pattern.size()) {
		if(str[i] == pattern[p]) {
			i++, p++, cont++;
		} else i++;
	}
	if(cont == pattern.size()) cout << "YES" << endl;
	else cout << "NO" << endl;
}