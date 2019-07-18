// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=562
#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	int tc;
	cin >> tc;
	for(int i = 0; i < tc; i++) {
		cin >> str;
		if(!str.compare("1") || !str.compare("4") || !str.compare("78"))
			cout << "+" << endl;
		else if((str[str.length() - 2] == 51) && (str[str.length() - 1] == 53))
			cout << "-" << endl;
		else if((str[0] == 57) && (str[str.length() - 1] == 52))
			cout << "*" << endl;
		else
			cout << "?" << endl;
	}	
}
