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
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0, cont = 0;
	set<char> bucket;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= 'A' && s[i] <='Z') {
			if(cont > ans) ans = cont;
			cont = 0;
			bucket.clear();
		} else {
			bucket.insert(s[i]);
			cont = bucket.size();
		}
	}
	if(cont > ans) ans = cont;
	cout << ans << endl;
}