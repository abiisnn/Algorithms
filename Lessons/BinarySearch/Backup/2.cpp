#include<bits/stdc++.h>
using namespace std;

// TLE
// 1 seg tiempo. 1e8
// n = 1e6, 0 = 1e6   n * q = 1e12
/*
	10
	1 3 4 9 99 134 9908 44444 44445 444446
	5
	3 15 4 6 7
*/
int main() {
	int n, num; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++) { // O(q*n) --> Cuádratico
		cin >> num;
		bool flag = false;
		for(int j = 0; j < n; j++) { // O(n)
			if(v[j] == num) {
				flag = true;
				break;
			}
		}
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}