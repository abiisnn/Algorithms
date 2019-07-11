// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=1365
#include<bits/stdc++.h>
#include <math.h>

using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int getNumber(char a) {
	int b = a;
	if((b >= 65) && (b <= 90)) 
		b = a - 64;
	else if((b >= 97) && (b <= 122))
		b = a - 96;
	else 
		b = 0;
	return b;
}
int goToNumber(char c) {
	return c - 48;
}
int loveCalculator(string number) {
	int n, result;
	n = 0;
	for(int i = 0; i < number.length(); i++) 
		n += getNumber(number.at(i));

	number = to_string(n); 
	// cout << "Number: " << number << endl;
	if(number.length() == 1) 
		return n;
	else {
		n = 0;
		while(number.length() > 1) {
			for(int i = 0; i < number.length(); i++) 
				n += goToNumber(number.at(i));
			number = to_string(n);
			result = n; n = 0;
		}	
		return result;		
	}
}
float calculeP(float a, float b) {
	float aux = a;
	a = max(a, b);
	b = min(aux, b);
	return (b * 100) / a;
}
int main() {
	int a, b;
	string firstName, secondName;
	while(getline(cin, firstName), firstName.length() > 0) {
		getline(cin, secondName);

		a = loveCalculator(firstName);
		b = loveCalculator(secondName);

		if(a == b)
			cout << "100.00 %" << endl;
		else {
			printf("%.2f", calculeP(a, b));
			cout << " %" << endl;
		}
		firstName = "";
	}
}