// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3710
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int compareString(string number, string toCompare) {
	int cont = 0, n, tc;
	for(int i = 0; i < 3; i++) {
		n = number.at(i);
		tc = toCompare.at(i);
		if(n != tc)
			cont++;
	}
	return cont;
}

int main() {
	int tc, n;
	string number, one, two;
	one = "one";
	two = "two";
	cin >> tc;
	while(tc) {
		cin >> number;
		if(number.length() == 5) 
			cout << "3" << endl;
		else {
			n = compareString(number, two);
			if(n > 1) 
				cout << "1" << endl;
			else
				cout << "2" << endl;
		}
		tc--;
	}
}