// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=2730
#include<bits/stdc++.h>
using namespace std;

int main() {
	int A, C, i;
	int number, block, ant, max;

	while(cin >> A, A != 0) {
		cin >> C;
		vector<int> v(C, 0);
		for(i = 0; i < C; i++) {
			cin >> number;
			v[i] = number;
		}
		block = 0;
		ant = v[0];
		max = ant;
		for(i = 1; i < C; i++) {
			cout << "Block: " << block << endl;
			if(v[i] >= max) {
				block += v[i] - max;
			}
			else if(ant > v[i]) {
				block += ant - v[i];
			}
			if(v[i] > max)
				max = v[i];
		}
		cout << block << endl;
	}
}