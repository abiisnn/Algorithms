// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3912
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int imHere, iGo;
	int minN, maxN, answer;

	cin >> imHere;
	while(imHere != -1) {
		cin >> iGo;

		minN = min(imHere, iGo);
		maxN = max(imHere, iGo);

		if(minN ==  maxN) 
			cout << 0 << endl;
		else {
			imHere = maxN - minN;
			iGo = 100 - maxN + minN;
			cout << min(imHere, iGo) << endl;
		}
		cin >> imHere;
	}
}