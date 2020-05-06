// https://codeforces.com/contest/1295/problem/C
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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
 
int main() {
	optimizar_io
	int q; cin >> q;
	string s, t;
	while(q--) {
		cin >> s >> t;
		vector<vector<int>> ABC(26, vector<int>(0));
		fore(i, 0, s.size()) ABC[s[i] - 'a'].pb(i); 
 
		int last = -1, cont = 1, next;
		bool flag = true;
		fore(i, 0, t.size()) {
			vector<int> &v = ABC[t[i] - 'a'];
			vector<int>::iterator next = std::lower_bound(v.begin(), v.end(), last+1);
			if(next != v.end()) last = (*next);
			else {
				cont++;
				if(v.size() > 0) last = v[0];
				else {
					flag = false;
					break;
				}
			}
		}
		if(flag) cout << cont << endl;
		else cout << -1 << endl;
	}
 
}