#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 105

int main() {
	optimizar_io
	vector<int> bucket(MAX, 0);
	int n, num, l, r;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> num;
		bucket[num]++;
	}
	cin >> l >> r;
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		if(i >= l && i <= r) {
			ans += bucket[i];
		}
	}
	cout << ans;
}