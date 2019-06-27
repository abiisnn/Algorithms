// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3794
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, l, w , h, i;
	i = 0;
	cin >> tc;
	while(tc) {
		i++;
		cin >> l >> w >> h;
		if((l <= 20) && (w <= 20) && (h <= 20)) 
			cout << "Case " << i << ": good" << endl;
		else
			cout << "Case " << i << ": bad" << endl;
		tc--;
	}
}