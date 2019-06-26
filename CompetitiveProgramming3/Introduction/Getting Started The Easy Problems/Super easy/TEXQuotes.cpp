// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=208
#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
int getNumber(char letter) {
	int i = letter;
	return i;
}

int main() {
	string cad = "", final = "";
	char c;
	int i, cont;
	cont = 0;
	getline(cin, cad);
	while(cad.compare("")) {
		for(i = 0; i < cad.length(); i++) {
			c = cad.at(i);
			if(getNumber(c) == 34) {
				cont++;
				if((cont % 2) == 1) {
					final += "``"; 
				}
				else {
					final += "''";
					cont = cont % 2;
				}
			}
			else {
				final += c;
			}
		}
		cout << final << endl;
		final = "";
		cad = "";
		getline(cin, cad);
	}
}