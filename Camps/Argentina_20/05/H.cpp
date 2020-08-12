#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 101
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	string s; cin >> s;

	string pat = "hello";
	int p = 0;
	bool flag = false;
	fore(i, 0, s.size()) {
		if(s[i] == pat[p]) p++;
		if(p == 5) flag = true;
	}
	if(p == pat.size() && flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}