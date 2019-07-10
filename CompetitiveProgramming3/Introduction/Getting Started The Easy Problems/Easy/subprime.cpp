// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2726
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int B, N, D, C, V;
	int i, cant, flag;

	cin >> B >> N;
	while(B || N) {
		vector<int> banks(B + 1, 0);
		for(i = 1; i <= B; i++) {
			cin >> cant;
			banks[i] = cant; 
		}
		for(i = 0; i < N; i++) {
			cin >> D >> C >> V;
			banks[D] = banks[D] - V;
			banks[C] = banks[C] + V;
		}
		flag = 1;
		for(i = 0; i < banks.size(); i++) {
			if(banks[i] < 0) {
				flag = 0;
				break;
			}
		}
		if(flag) 
			cout << "S" << endl;
		else 
			cout << "N" << endl;

		cin >> B >> N;
	}
}