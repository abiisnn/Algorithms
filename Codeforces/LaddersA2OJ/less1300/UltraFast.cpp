// https://codeforces.com/problemset/problem/61/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	string a, b, c;
	cin >> a >> b;

	c = "";
	for(int i = 0 ; i < a.size(); i++) {
		if(a[i] == b[i]) c += "0";
		else c += "1";
	}
	cout << c << endl;
}