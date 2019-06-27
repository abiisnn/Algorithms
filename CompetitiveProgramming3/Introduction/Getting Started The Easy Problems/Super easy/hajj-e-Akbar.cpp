// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=4022
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	string c;
	cin >> c;
	int i = 0;
	while(c.compare("*")) {
		i++;
		if(!c.compare("Hajj")) 
			cout << "Case " << i << ": Hajj-e-Akbar" << endl;
		else
			cout << "Case " << i << ": Hajj-e-Asghar" << endl;
		cin >> c;
	}
}