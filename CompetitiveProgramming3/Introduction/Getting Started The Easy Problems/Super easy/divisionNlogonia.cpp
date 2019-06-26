// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2493
#include<bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;

int main() {
	ll a, b, x, y;
	int tc, i;

	while(scanf("%d", &tc), tc) {
		cin >> x >> y;
		for(i = 0; i < tc; i++) {
			cin >> a >> b;
			if((a == x) && (b > y)) {
				cout << "divisa" << endl;
			} else if((a > x) && (b == y)) {
				cout << "divisa" << endl;
			} else if((a == x) && (b < y)) {
				cout << "divisa" << endl;
			} else if((a < x) && (b == y)) {
				cout << "divisa" << endl;
			} else if((a == x) && (b == y)) {
				cout << "divisa" << endl;
			} else if((a > x) && (b > y)) {
				cout << "NE" << endl;
			} else if((a < x) && (b > y)) {
				cout << "NO" << endl;
			} else if((a < x) && (b < y)) {
				cout << "SO" << endl;
			} else if((a > x) && (b < y)) {
				cout << "SE" << endl;
			}
		}
	}
} // main
