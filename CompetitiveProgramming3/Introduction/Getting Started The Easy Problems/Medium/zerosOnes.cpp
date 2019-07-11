// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=1265
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

string cad;
void vefiry(int i, int j) {
	int a, b, cont, aux;
	cont = 0; aux = 0;
	a = cad[i];
	for(int k = i+1; k <= j; k++) {
		aux++;
		b = cad[k];
		if(a == b)
			cont++;
		a = b;
	}
	if(cont == aux) 
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main() {
	int query, i, j, k, l, a, b;
	l = 1;
	while(cin >> cad, cad.length() > 0) {
		cin >> query;
		cout << "Case " << l << ":" << endl;
		for(k = 0; k < query; k++) {
			cin >> a >> b;
			i = min(a, b);
			j = max(a, b);
			if(i == j)
				cout << "Yes" << endl;
			else
				vefiry(i, j);
		}
		cad = ""; l++;
	}
}