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
vector<char> m(11);

int findGreater(string s) {
	int index = -1;
	fore(i, 0, s.size()) {
 		if(m[s[i] - '0'] > s[i]) {
			index = i;
			break;
		}
	}
	return index;
}
int main() {
	string s;
	int n; cin >> n >> s;
	char val;
	for(int i = 0; i < 10; i++) {
		cin >> val;
		m[i + 1] = val;	
	}
	// int index = findGreater(s);
	// if(index != -1) {
	// 	for(int i = index; i < s.size(); i++) {
	// 		if(m[s[i] - '0'] >= s[i]) {
	// 			s[i] = m[s[i] - '0'];
	// 		} else break;
	// 	}
	// }
	for(int i = 0; i < s.size(); i++) {
		if(m[s[i] - '0'] > s[i]) { // buscar pivote
			while(i < s.size() && m[s[i] - '0'] >= s[i]) {
				s[i] = m[s[i] - '0'];
				i++;
			}
			break;
		}
	}
	cout << s << endl;
	return 0;
}	