// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=2730
#include<bits/stdc++.h>
using namespace std;

int main() {
	int A, C, i;
	int number, block, ant, max;

	while(cin >> A, A != 0) {
		cin >> C;
		vector<int> v;
		for(i = 0; i < C; i++) {
			cin >> number;
			v.push_back(number);
		}
		ant = v[0]; max = ant; block = 0;
		for(i = 1; i < C; i++) {
			if((v[i] > ant) && (v[i] > max)) 
				block += v[i] - max;
			else if(ant > v[i])
				block += ant -i];
			if(v[i] > max)
				max = v[i];
			ant = v[i];
		}
		if(max != A)
			block += A - max;
		cout << block << endl;
	}
}