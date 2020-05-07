#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
	lli a = 0;
	for(lli i = 0; i <= 10; i++) a += (i * i);
	
	lli n = 10;
	lli b = (n * (n+1)) * (n * (n+1));
	b /= 4;
	cout << b - a << endl;
}