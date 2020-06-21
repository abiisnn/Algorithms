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

vector<int> poly(100, 0);
int stringtoInt(string num) {
	int n = 0;
	stringstream convert(num);
	convert >> n;
	return n;
}
void addCoficient(string cof) {
	if(!cof.size()) return;
	string num = "";
	int beg = -1;
	for(int i = 0; i < cof.size(); i++) {
		if(cof[i] == 'x') {
			beg = i;
			break;
		}
		num += cof[i];
	}
	if((num[0] == '-' or num[0] == '+') && num.size() == 1) num += '1';
	if(!num.size()) num += "1";	
	int n = stringtoInt(num);
	num = "";
	if(beg == -1) { poly[0] += n; return; } 
	fore(i, beg + 1, cof.size()) num += cof[i];
	if(num.size() == 0) num += "1";
	int exp = stringtoInt(num);
	poly[exp] += n;
}
string inttoString(int n) {
	stringstream ss;  
  	ss << n;  
  	string s;  
  	ss >> s;
  	return s;  
}

int main() {
	optimizar_io
	string s; cin >> s;
	string pol = "";
	fore(i, 0, s.size()) {
		if(s[i] == '-' or s[i] == '+') {
			addCoficient(pol);
			pol = "";
		}
		pol += s[i];
	}
	addCoficient(pol);
	vector<int> res(99, 0);

	for(int i = poly.size()-1; i >= 1; i--) {
		int cof = poly[i] * i;
		int exp = i - 1;
		res[exp] = cof;
	}
	string ans = "";
	for(int i = res.size()-1; i >= 0; i--) {
		if(res[i]) {
			string ter = inttoString(res[i]);
			if(ter[0] != '-') ter = "+" + ter;
			if(i != 0) ter += "x";
			if(i > 1) ter += inttoString(i);
			ans += ter;
		}
	}
	if(ans.size()) {
		if(ans[0] == '+') {
			string aux(ans, 1, ans.size()-1);
			ans = aux;
		}
		cout << ans << endl;
	} else cout << 0 << endl;
}