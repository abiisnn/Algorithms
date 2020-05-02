// https://codeforces.com/problemset/problem/266/B
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cont, block;
	string s;
	cin >> cont >> s;

	cont = 0, block = 0;
	for(int i = 0; i < s.size() - 1; i++) {
		if(s[i] == s[i + 1]) cont++;
		else {
			block += cont;
			cont = 0;
		}
	}
	block += cont;
	cout << block << endl;
}