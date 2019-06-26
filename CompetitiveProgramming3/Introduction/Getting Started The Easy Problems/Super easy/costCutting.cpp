// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2827
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int i, j, number, tc;
	cin >> tc;
	for(i = 0; i < tc; i++ ) {
		vector<int> v;
		for(j = 0; j < 3; j++) {
			cin >> number;
			v.push_back(number);
		}
		sort(v.begin(), v.end());
		cout << "Case " << i+1 << ": " << v[1] << endl;
	}
}