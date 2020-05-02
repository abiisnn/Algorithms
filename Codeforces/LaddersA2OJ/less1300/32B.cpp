// https://codeforces.com/problemset/problem/32/B
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string decoded;
	cin >> decoded;
	for(int i = 0; i < decoded.size(); i++) {
		if(decoded[i] == '.') cout << "0";
		if(decoded[i] == '-') {
			if(decoded[i + 1] == '.') cout << "1";
			else cout << "2";
			i++;
		}
	}
}