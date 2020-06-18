#include<bits/stdc++.h>
using namespace std;
// 1 seg tiempo. 
// n = 1e6, q = 1e6 
/*
	10
	1 3 4 9 99 134 9908 44444 44445 444446
	5
	3 15 4 6 7
*/
int lowerBound(vector<int> &v, int target) {
	int l = 0, r = v.size() - 1;
	while(l <= r) {
		int m = l + (r - l) / 2;
		if(v[m] < target) l = m + 1; 
		else if(v[m] > target) r = m - 1;
		else r = m - 1;
	}
	if(l >= v.size()) return -1;
	return l;
}
int main() {
	int n, num; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++) { // O(q*n) --> Cuádratico
		cin >> num;
		int ans = lowerBound(v, num);
		cout << "lowerBound de " << num << " esta en la posicion" << ans << endl;
	}

}

