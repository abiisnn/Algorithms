// // https://codeforces.com/group/jbdVtsXBjp/contest/258964/problem/E
#include<bits/stdc++.h>
using namespace std;

int main() {
	int y, w, m, g;
	cin >> y >> w;
	m = max(y, w);
	m = 7 - m;
	g = __gcd(m, 6);
	cout << m/g << "/" << 6/g << endl;
	return 0;
}