// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3431
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, i, j, n, cont, answer;
	cin >> tc;
	cont = 0;
	j = 0;
	while(tc != 0) {
		j++;
		for(i = 0; i < tc; i++) {
			cin >> n;
			if(n == 0) 
				cont++;
		}
		answer = tc - cont - cont;
		cont = 0;
		cout << "Case " << j << ": " << answer << endl; 
		cin >> tc;
	}
}