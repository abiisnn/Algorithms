// https://codeforces.com/problemset/problem/110/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	string s;
	cin >> s;
	int lucky = 0;
	for(int i = 0; i < s.size(); i++) {
		if((s[i] == '4') or (s[i] == '7')) lucky++;
	}
	ostringstream convert;
	convert << lucky;
	s = convert.str();
	lucky = 0;
	for(int i = 0; i < s.size(); i++) {
		if((s[i] == '4') or (s[i] == '7')) lucky++;
	}
	if(s.size() == lucky) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}