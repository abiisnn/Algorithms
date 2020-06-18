#include<bits/stdc++.h>
using namespace std;
// 1 seg tiempo. 
// n = 1e6
/* in:
	10
	1 3 4 9 99 134 9908 44444 44445 444446
	5
*/
int main() {
	int n, num; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	
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