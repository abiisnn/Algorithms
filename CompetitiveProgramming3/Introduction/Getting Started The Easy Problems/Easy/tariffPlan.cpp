// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3309
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
int getTariff(int n, int change, int price) {
	if((n < 30) && (change == 30)) 
		return 10;
	else if((n < 60) && (change == 60))
		return 15;
	else
		return (piso(n, change) + 1) * price;
}
int main() {
	int tc, n, i, caseN, number;
	int mile, juice;

	cin >> tc;
	caseN = 0;
	while(tc) {
		cin >> n;
		caseN++;
		mile = 0; juice = 0;
		for(i = 0; i < n; i++) {
			cin >> number;
			mile += getTariff(number, 30, 10);
			juice += getTariff(number, 60, 15);
		}
		if(mile == juice)
			cout << "Case " << caseN << ": Mile Juice " << mile << endl;
		else if(mile < juice)
			cout << "Case " << caseN << ": Mile " << mile << endl;
		else
			cout << "Case " << caseN << ": Juice " << juice << endl;
		tc--;
	}
}