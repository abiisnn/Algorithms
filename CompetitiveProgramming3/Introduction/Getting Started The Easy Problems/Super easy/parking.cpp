// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=2349
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, i, j, n, number, aux, sum, end;
	sum = 0;
	cin >> tc;
	for(i = 0; i < tc; i++) {
		cin >> n;
		if(n == 1) {
			cout << "0" << endl;
		}
		else {
			vector<int> v;
			for(j = 0; j < n; j++) {
				cin >> number;
				v.push_back(number);
			}
			sort(v.begin(), v.end());	
			for(j = 0; j < v.size() - 1; j++) {
				number = v[j];
				aux = v[j + 1];
				number = aux - number;
				sum += number; 
			}		
			sum += v[v.size() - 1] - v[0];
			cout << sum << endl;
		}
		sum = 0;
	}	
}