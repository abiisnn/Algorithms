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
	string str1, str2;
	cin >> str1 >> str2;

	bool ans = true;
	if(str1.size() != str2.size()) ans = false;
	else {
		vector<int> dif;
		fore(i, 0, str1.size()) {
			if(str1[i] != str2[i]) dif.pb(i);
		}
		if(dif.size() == 2) {
			if((str2[dif[0]] != str1[dif[1]]) or (str2[dif[1]] != str1[dif[0]])) 
				ans = false;
		}
		if(dif.size() >= 3 or dif.size() == 1) ans = false; 
	} 
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}