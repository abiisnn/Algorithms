// https://codeforces.com/problemset/problem/1176/B
#include<bits/stdc++.h>
using namespace std;
int main() {
	int tc, n;
	long long int a;
	cin >> tc;
	while(tc--) {
		cin >> n;
		long long int sum = 0, n1 = 0, n2 = 0, mn, mx;
		for(int i = 0; i < n; i++) {
			cin >> a;
			a %= 3;
			if(a == 0) sum += 1;
			else if(a == 1) n1++;
			else n2++;
		}
		mn = min(n1, n2);
		mx = max(n1, n2);

		sum += mn + (mx - mn) / 3;
		cout << sum << endl;
	}
}