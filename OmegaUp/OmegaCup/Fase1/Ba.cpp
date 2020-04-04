#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 105

int main() {
	optimizar_io
	int n, k; 
	cin >> n >> k;
	vector<int> nums(n, 0); // [0, 0, 0, 0, ..., 0]
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(nums[i] == k) {
			ans++;
		}
	}
	cout << ans << endl;
}