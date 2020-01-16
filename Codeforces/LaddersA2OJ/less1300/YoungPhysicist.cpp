// https://codeforces.com/problemset/problem/69/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	lli n, x, y, z, a, b, c;
	cin >> n;
	a = 0, b = 0, c = 0;
	while(n--) {
		cin >> x >> y >> z;
		a += x;
		b += y;
		c += z;
	}

	if((a == 0) && (b == 0) && (c == 0)) cout << "YES" << endl;
	else cout << "NO" << endl;
}