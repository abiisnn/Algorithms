#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 20000000
#define MOD 1000000007
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	string s; cin >> s;
	stack<char> st;

	for(char i: s) {
		if(i == '0' or i == '1') st.push(i);
		else if(!st.empty()) {
			st.pop();
		}
	}

	string ans = "";
	while(!st.empty()) {
		ans.pb(st.top());
		st.pop();
	}
	reverse(all(ans));
	cout << ans << endl;
}