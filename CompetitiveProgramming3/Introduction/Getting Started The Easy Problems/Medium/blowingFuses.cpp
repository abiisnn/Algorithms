// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=602
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int n, m, c; 
	int number, capacity, operation, max, flag;
	int i, j;
	j = 0;
	while(1) {
		cin >> n >> m >> c;
		if(((n == 0) && (m == 0) && (c == 0)))
			break;
		vector<int> consumption(n + 1, 0);
		vector<int> devices(n + 1, 0);
		vector<int> query(m + 1, 0);
		j++;

		for(i = 1; i <= n; i++) {
			cin >> number;
			consumption[i] = number;
		}
		capacity = 0; max = 0; flag = 0;
		for(i = 0; i < m; i++) {
			cin >> number;
			query[i] = number;
		}
		for(i = 0; i < m; i++) {
			number = query[i];
			// I am in turn on
			if(consumption[number] == devices[number]) {
				capacity = capacity - consumption[number]; 
				devices[number] = 0;
			}
			else { // I am turn off
				operation = capacity + consumption[number];
				if(operation <= c) {
					capacity = operation;
					devices[number] = consumption[number];
					if(capacity > max)
						max = capacity; 
				}
				else {
					flag = 1;
					break;
				}
			}
		}
		cout << "Sequence " << j << endl;
		if(!flag) {
			cout << "Fuse was not blown." << endl << "Maximal power consumption was " << max << " amperes." << endl;
		}
		else 
			cout << "Fuse was blown." << endl;
		cout << endl;
	}
}