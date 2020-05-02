//https://codeforces.com/problemset/problem/228/A
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

void changeString(string &s) {
	int l = s.size() - 2;
	stringstream ss;
	ss << l;
	s = s[0] + ss.str() + s[s.size() - 1];
}
int main() {
	int n; 
	string s;
	cin >> n;
	while(n--) {
		cin >> s;
		if(s.size() > 10) changeString(s);	
		cout << s << endl;
	}
	return 0;
}