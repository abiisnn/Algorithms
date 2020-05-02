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
bool canBeCreated(int l, int r, string &s, string &t) {
	bool ans = false;
	int tIndex = 0, sIndex = l, match = 0;
	while(sIndex < r && tIndex < t.size()) {
		if(s[sIndex] == t[tIndex]) {
			sIndex++; tIndex++; match++;
		} else sIndex++;
	}
	if(match == t.size()) ans = true;
	return ans;
}

int main() {
	optimizar_io
	string s, t, test;
	int dis = 0, maxDis = 0;
	cin >> s >> t;
	for(int i = 0; i < s.size(); i++) {
		for(int j = i; j < s.size(); j++) { // (n * (n+1) )/ 2
			test = s.substr(0, i) + s.substr(j+1, s.size()-j);
			if(canBeCreated(0, test.size(), test, t)) {
				int dis = j - i + 1;
				if(dis > maxDis) maxDis = dis;
			}
		}
	}
	cout << maxDis << endl;
}