#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 105

int main() {
	optimizar_io
	int n, aux, L, R; 
	cin >> n;
	vector<int> nums(n, 0); // [0, 0, 0, 0, ..., 0]
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cin >> L >> R;

	int ans = 0;
	for(int i = 0; i < n; i++) {
		if((nums[i] >= L) && (nums[i] <= R)) {
			ans++;
		}
	}
	cout << ans << endl;
}