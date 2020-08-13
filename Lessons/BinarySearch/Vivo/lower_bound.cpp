#include<bits/stdc++.h>
using namespace std;

int lower(vector<int> &v, int target) {
	int l = 0, r = v.size() - 1;

	while(l <= r) {
		int m = l + (r - l) / 2; // mitad
		if(v[m] > target) r = m - 1;
		else if(v[m] < target) l = m + 1;
		else r = m - 1; // v[m] == target
	}
	if(l >= v.size()) return -1;
	return l;
}
int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());
	int target; cin >> target;
	cout << "lower en pos: " << lower(v, target) << endl;
}