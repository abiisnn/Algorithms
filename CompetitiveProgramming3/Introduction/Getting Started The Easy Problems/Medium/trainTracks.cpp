// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=2633
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, m, f;
	string cad; 

	cin >> tc;
	cin.ignore();
	for(int i = 0; i < tc; i++) {
		getline(cin, cad);
		m = 0; f = 0;
		for(int j = 0; j < cad.length(); j++) {
			if(cad[j] == 77)
				m++;
			else if(cad[j] == 70)
				f++;
		}
		if((m == 1) && (f == 1))
			cout << "NO LOOP" << endl;
		else if(m == f) 
			cout << "LOOP" << endl;
		else 
			cout << "NO LOOP" << endl;
	}	
}