#include <iostream>
#include <vector>
#include <stdio.h>     
#include<math.h>
#include <algorithm>    // std::sort
using namespace std;

int main(int argc, char const *argv[])
{
	int num, n, sum, acumulado, i, j, aux, in;
	vector<int> vA, vB, vSum, vAux;
	cin >> n;
	for(i = 0; i < n; i++) {
		cin >> num;
		vA.push_back(num);
	} 
	for(i = 0; i < n; i++) {
		cin >> num;
		vB.push_back(num);
	} 
	acumulado = 0; aux = 0;
	in = vA.size() - 1;
	for(i = in; i >=0; i--) {
		sum = vA[i] + vB[i];
		if(acumulado == 1) {
			sum = sum + 1;
			acumulado = 0;
		}
		if(i == 0) {
			vSum.push_back(sum);
			break;
		}
		if(sum <= 9) 
			aux = sum;
		
		if(sum >=10) {
			aux = sum - 10;
			acumulado = 1;
		}
		vSum.push_back(aux);
	}

	for(i = vSum.size()-1; i >= 0; i--) 
		vAux.push_back(vSum[i]);
	
	sum = 0;
	for(i = 0; i < vSum.size(); i++)
		sum += vAux[i];
	if(sum == 0)
		cout << "0";
	else {
		for(i = 0; i < vAux.size(); i++) {
			if(vAux[i] != 0) {
				for(j = i; j < vAux.size(); j++)
					cout << vAux[j]; 
				break;
			}
		}	
	}
	return 0;
}
