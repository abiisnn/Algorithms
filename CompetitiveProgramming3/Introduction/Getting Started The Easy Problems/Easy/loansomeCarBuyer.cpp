// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1055
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

double porcentage(double p, double por) {
	double ans;
	ans = p * por;
	ans = p - ans;
	return ans;
}
int main() {
	int month, numberDepre, monthCounter;
	double i;
	double downPayment, amountLoan, porcent, depre , months;
	double initialPay, payMonth, carWorth, borrower;

	cin >> months;
	while(months > 0) {
		cin >> downPayment >> amountLoan >> numberDepre;
		
		vector<double> depreciation(101, -1);

		// Read depreciation for month
		for(i = 0; i < numberDepre; i++) {
			cin >> month >> porcent;
			depreciation[month] = porcent;
		}

		payMonth = amountLoan / months;
		initialPay = amountLoan + downPayment;
		carWorth = initialPay;

		i = 0;
		while(1) {
			if(depreciation[i] != -1)
				depre = depreciation[i];
			carWorth = porcentage(carWorth, depre);
			borrower = amountLoan - (i * payMonth);
			
			if(borrower < carWorth) 
				break;
			i++;
		}
		if(i == 1) 
			cout << "1 month" << endl;
		else
			cout << i << " months" << endl; 
		cin >> months;
	}
}