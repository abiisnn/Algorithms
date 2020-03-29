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

bool correctOrdern(string str) {
	int i;
	bool ans = true;
	if(str[0] != 'a') ans = false;
	else {
		for(i = 0; i < str.size(); i++) {
			if(str[i] != 'a') {
				break;
			}
		}
		if(str[i] == 'b') {
			for(i = i; i < str.size(); i++) {
				if(str[i] != 'b') {
					break;
				}
			}
		    if(str[i] == 'c') {
				for(i = i; i < str.size(); i++) {
					if(str[i] != 'c') {
						ans = false;
						break;
					}
				}
			} else ans = false;
		} else ans = false;
	} 
	return ans;
}
int main() {
	optimizar_io
	string str;
	cin >> str;

	map<char, int> bucket;
	fore(i, 0, str.size()) {
		bucket[str[i]]++;
	}
	bool ans = true;
	int a = bucket['a'], b = bucket['b'], c = bucket['c'];
	if(((a > 0) && (b > 0) && (c > 0))) {
		if((a == b && b == c && c == a) or (a == c) or (b == c)) {
			if(!correctOrdern(str)) ans = false; 
		} else ans = false;
	} else ans = false;

	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}