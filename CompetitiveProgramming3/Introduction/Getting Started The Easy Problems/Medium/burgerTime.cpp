// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=2708
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int calcule(int R, int D) {
	int auxR, auxD;
	auxR = R; auxD = D;
	R = max(auxR, auxD);
	D = min(auxR, auxD);
	return R - D;
}

int main() {
	int L;
	string cad;
	while(cin >> L, L != 0) {
		cin >> cad;
		int flag, posR, posD, number;
		vector<int> distance; 
		flag = 0; posR = -1; posD = -1;
		for(int i = 0; i < cad.length(); i++) {
			if(cad[i] == 90) { // Z
				flag = 1; 
				break;
			}
			else if(cad[i] == 82) { // R
				posR = i;
				if(posD != -1) {
					number = calcule(posR, posD);
					distance.push_back(number);
				}
			}
			else if(cad[i] == 68) { // D
				posD = i;
				if(posR != -1) {
					number = calcule(posR, posD);
					distance.push_back(number);
				}
			}
		}
		if(flag) 
			cout << "0" << endl;
		else {
			sort(distance.begin(), distance.end());
			cout << distance[0] << endl;
		}
	}
}