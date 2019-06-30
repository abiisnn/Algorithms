// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=1985
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int piso(int a, int b) {
	if((a >= 0 &&  b > 0) || (a < 0 && b < 0)) 
		return a / b;
	else {
		if(a % b == 0) return a / b;
		else return a / b - 1;
	}
}
int main() {
	int tc, x, y, answer;
	cin >> tc;
	while(tc) {
		cin >> x >> y;
		x = piso(x, 3);
		y = piso(y, 3);
		answer = x * y;
		cout << answer << endl;
		tc--;
	}
}