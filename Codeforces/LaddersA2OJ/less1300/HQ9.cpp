// https://codeforces.com/contest/133/problem/A
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
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	bool flag = false;
	cin >> s;

	fore(i, 0, s.size()) {
		if((s[i] == 'H') or (s[i] == 'Q') or (s[i] == '9')) flag = true;
	}	
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}