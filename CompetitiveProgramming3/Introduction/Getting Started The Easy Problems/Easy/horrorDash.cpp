// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2899
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, n, number;
	int i, j;

	cin >> tc;
	for(i = 0; i < tc; i++) {
		cin >> n;
		vector<int> v;
		for(j = 0; j < n; j++) {
			cin >> number;
			v.push_back(number);
		}
		sort(v.begin(), v.end());
		cout << "Case " << i+1 << ": " << v[v.size() - 1] << endl; 
	}
}