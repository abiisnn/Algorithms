// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3093
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, number;
	int one, second, first;
	int i, verify;

	cin >> tc;
	cout << "Lumberjacks:" << endl;
	while(tc) {
		cin >> one >> second;
		verify = 0;
		if(one > second) {
			cout << one << " > " << second << endl;
			verify = 1;
		}

		if(verify) {
			for(i = 0; i < 7; i++) {
				cin >> first;
				cin >> number;
				if(number > first) {
					cout << "Unordered" << endl; 
					break;
				}
				first = number;
			}
			cout << "Ordered" << endl; 
		}
		else {
			for(i = 0; i < 7; i++) {
				cin >> first;
				cin >> number;
				if(number < first) {
					cout << "Unordered" << endl; 
				}
				first = number;
			}
			cout << "Ordered" << endl; 
		}
		tc--;
	}
}