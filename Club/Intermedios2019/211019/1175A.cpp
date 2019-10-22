#include<bits/stdc++.h>
using namespace std;

long long int cont(long long int a, long long int b) {
	long long int c = 0;
	while( b != 0) {
		long long int r = a % b;
		a = b;
		b = r;
		c++;
	}
	return c;
}
int main() {
	int tc;
	long long int n, k;
	cin >> tc;
	while(tc--) {
		cin >> n >> k;
		cout << cont(n, k) << endl;
	}
}