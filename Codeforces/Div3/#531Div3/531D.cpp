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
	string s;
	cin >> n >> s;
	map<char, int> bucket;
	map<char, int> faltan;
	int toca = n / 3;
	string pattern = "012";
	fore(i, 0, pattern.size()) faltan[pattern[i]] = toca;
	
	string aux(n, ' ');
	fore(i, 0, n) {
		bucket[s[i]]++;
		int sz = bucket[s[i]];
		if(sz <= toca) {
			aux[i] = s[i];
			faltan[s[i]]--;
		}
	}

	int p = 0, i = 0;
	while(i < n) {
		int hay = faltan[pattern[p]];
		if(aux[i] == ' ') {
			if(hay) {
				aux[i] = pattern[p];
				faltan[pattern[p]]--;
				i++;
			} else p++;
		} else i++;
		
	}
	cout << aux << endl;
	return 0;
}