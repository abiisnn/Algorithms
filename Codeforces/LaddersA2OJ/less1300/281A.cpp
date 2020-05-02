// https://codeforces.com/problemset/problem/281/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	if(s[0] >= 97) s[0] -= 32; 
	cout << s << endl;
}