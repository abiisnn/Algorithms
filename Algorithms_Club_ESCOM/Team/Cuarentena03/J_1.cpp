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
 
int find(string s, int a, int b, char target) {
	int ans = -1;
	for(int i = a; i <= b; i++) {
		if(int(s[i]) < int(target)) {
			ans = i;
		}
	}
	return ans;
}
int main() {
	optimizar_io
	string s; cin >> s;
	string original = s;
	int pib = -1;
	for(int i = s.size()-1; i >= 1; i--) {
		if(int(s[i-1]) > int(s[i])) {
			pib = i-1;
			break;
		}
	}
	string ans;
	bool flag = true;
	if(pib != -1) {
		int pos = find(s, pib+1,  s.size()-1, s[pib]);
		if(pos != -1) {
			// if(pib == 0 && s[pos] == '0') flag = false; 
			swap(s[pos], s[pib]);
			sort(s.begin()+pib+1, s.end());
			reverse(s.begin()+pib+1, s.end());
			cout << s << endl;
		}
	}
	if(s[0] == '0') flag = false;
	int cont = 0;
	if(flag) {
		fore(i, 0, s.size()) {
			if(s[i] != original[i]) {
				cont++;
			}
		}
		if(cont == 2) cout << s << endl;
		else cout << -1<<endl;
	} else cout << -1 <<endl;
}