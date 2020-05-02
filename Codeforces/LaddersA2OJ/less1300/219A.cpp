#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	string str; cin >> str;

	map<char, int> m;
	fore(i, 0, str.size()) m[str[i]]++;
	
	bool flag = true;
	for(auto &i: m) {
		if((i.second % n) != 0) {
			flag = false;
			break;
		}
	}
	if(flag) {
		string ans = "";
		for(auto &i: m) {
			for(int j = 0; j < (i.second) / n; j++) ans += i.first;
		}
		string com = "";
		fore(i, 0, n) com += ans;
		cout << com << endl;
	} else cout << -1 << endl;
}