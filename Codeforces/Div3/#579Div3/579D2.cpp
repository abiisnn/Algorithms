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
#define MAX 200009
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void getRG(vector<int> &rg, string &s, string &t) {
	int indexS = s.size()-1, indexT = t.size()-1;
	while(indexS >= 0 && indexT >= 0) {
		if(s[indexS] == t[indexT]) {
			rg[indexT] = indexS;
			indexS--; indexT--;
		} else indexS--;
	}
}

int main() {
	optimizar_io
	string s, t;
	cin >> s >> t;
	// Get RG from s:
	vector<int> rg(t.size());
	getRG(rg, s, t);
	
	int rpos = s.size() - 1, ans = 0, indexT = 0;
	fore(i, 0, s.size()) {
		rpos = s.size() - 1;
		if(indexT < t.size()) rpos = rg[indexT] - 1;
		ans = max(ans, rpos - i + 1);
		if(indexT < t.size() && t[indexT] == s[i]) indexT++;
	}
	cout << ans << endl;
}