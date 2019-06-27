// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1241
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, f;
	int size, animals, env;
	int sum;
	int i;

	cin >> tc;
	while(tc) {
		cin >> f;
		sum = 0;
		for(i = 0; i < f; i++) {
			cin >> size >> animals >> env;
			sum += size * env;
		} 
		cout << sum << endl;
		tc--;
	}
}