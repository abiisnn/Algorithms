// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3093
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

void verifyOrder(vector<int> v, int begin, int end) {
	int aux, num, verify;
	verify = 0;
	if(!begin){
		aux = v[0];
		for(int i = 1; i < 10; i++) {
			num = v[i];
			if(num < aux) {
				verify = 1;
				break;
			}
			aux = num;
		}
		if(verify) 
			cout << "Unordered" << endl;
		else 
			cout << "Ordered" << endl;
	} else {
		aux = v[9];
		for(int i = 8; i >= 0; i--) {
			num = v[i];
			if(num < aux) {
				verify = 1;
				break;
			}
			aux = num;
		}
		if(verify) 
			cout << "Unordered" << endl;
		else 
			cout << "Ordered" << endl;
	}
}

int main() {
	int tc, number;
	int b, end;
	int i, verify;
	
	cin >> tc;
	cout << "Lumberjacks:" << endl;
	while(tc) {
		vector<int> v;
		for(i = 0; i < 10; i++) {
			cin >> number;
			v.push_back(number);
		}
		b = 0;
		end = 9;
		if(v[0] > v[1]) {
			b = 9;
			end = 0;
		} 
		verifyOrder(v, b, end);
		tc--;
	}
}