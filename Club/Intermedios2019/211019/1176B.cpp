#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc, n;
	int a;
	cin >> tc;
	while(tc--) {
		cin >> n;
		long long int sum = 0, aux = 0;
		for(int i = 0; i < n; i++) {
			cin >> a;
			a %= 3;
			sum += a;
		}
		cout << sum/3 << endl;
	}
}