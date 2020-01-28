// https://codeforces.com/group/jbdVtsXBjp/contest/258964/problem/B
#include<bits/stdc++.h>
#define MAXN 57
using namespace std;

int main() {
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		cout << s[i];
	int l = s.size();
	while(l--) {
		cout << s[l];
	}
	cout << endl;

	return 0;
}