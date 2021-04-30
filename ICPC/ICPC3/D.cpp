#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

bool isNumber(char s) { return (s >= '0' && s <= '9'); }
lli convert(string s) {
    stringstream idk(s);   
    lli x = 0; idk >> x;
    return x;
}
void solve() {
	string s; int k; cin >> s >> k;

	bool can = true;
	string ans = "";
	for(int i = 0; i < (int)s.size(); i++) {
		if(isNumber(s[i])) {
			string numHere = "";
			while(i < (int)s.size() && isNumber(s[i])) {
				numHere += s[i];
				i++;
			}
			char currentChar = s[i];
			lli num = convert(numHere);
			if(ans.size() + num > k) {
				can = false;
				break;
			}
			fore(j, 0, num) ans.pb(currentChar);
		} else ans += s[i];
	}
	if(can && ans.size() <= k) cout << ans << endl;
	else cout << "unfeasible" << endl;
}

int main() {
	int t; cin >> t;
	while(t--) solve();
}