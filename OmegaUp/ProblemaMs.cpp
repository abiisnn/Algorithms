#include <iostream>
#include <vector>
#include <stdio.h>     
#include<math.h>
#include <algorithm>    // std::sort
using namespace std;

int main(int argc, char const *argv[])
{
	int i, n, sum, num, m, max, sig, cont, contAnt, moda;
	vector<int> v;
	cin >> n;

	for(i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	} 

	// Media
	sum = 0;
	for(i = 0; i < n; i++)
		sum = sum + v[i];
	sum = sum / n;
	cout << "Media: " << floor(sum) << endl;
	
	sort(v.begin(), v.end());

	// Moda
	cont = 1, contAnt = 0; moda = v[0]; 
	for(i = 0; i < n-1; i++) {
		num = v[i];
		sig = v[i+1];
		//cout << "Actual" << num << " Siguiente " << sig << endl;
		if(num == sig)
			cont++;
		m = n-2;
		if(num!=sig || i==m){
			//cout << cont << " Es mayor que" << contAnt << endl;
			if(cont > contAnt) {
				max = cont;
				moda = v[i];
				contAnt = cont;
				cont = 1; 
			}
		}
	}
	cout << "Moda: " << moda << endl;
	
	// Mediana
	num = (v.size() - 1) /  2;
	cout << "Mediana: " << v[num] << endl;  
	
	return 0;
}
