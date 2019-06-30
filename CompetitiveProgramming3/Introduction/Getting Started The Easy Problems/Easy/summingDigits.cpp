// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2307
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

ll getNumber(char c) {
	return c - 48;
}
int main() {
	ll n, i;
	char c;
	string number;
	cin >> number;
	n = 0;
	while(number.compare("0")) {
		while(number.length() > 1) {
			for(i = 0; i < number.length(); i++) {
				n += getNumber(number.at(i));
			}
			number = to_string(n);
			n = 0;
		}		
		cout << number << endl;
		cin >> number;
	}
}