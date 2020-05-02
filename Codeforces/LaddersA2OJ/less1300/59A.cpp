// https://codeforces.com/problemset/problem/59/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

void toLower(string s) {
	for(int i = 0; i < s.size(); i++) 
		if(s[i] < 97 ) s[i] += 32;
	cout << s << endl;
}
void toUpper(string s) {
	for(int i = 0; i < s.size(); i++) 
		if(s[i] >= 97 ) s[i] -= 32;
	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int upper = 0, lower = 0;
	for(int i = 0; i < s.size(); i++) 
		if(s[i] >= 97) lower++;

	upper = s.size() - lower;
	if(lower >= upper) toLower(s);
	else toUpper(s);
}