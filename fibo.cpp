#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main() {
	vector<lli> fibo(46);

	fibo[0] = fibo[1] = 1;
	for(int i = 2; i < 46; i++) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	}

	for(int i = 0; i < 46; i++) {
		cout << "F " << i << " = " << fibo[i] << "\n";
	}
}