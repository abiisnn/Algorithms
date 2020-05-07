#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

long long int greatestProduct(string a) {
	long long int ans = 1;
	for(int i = 0; i < a.size(); i++) {
		int n = a[i] - '0';
		ans *= n;
	}
	return ans;
}

int main() {
	int n, s;
	string digits = "", aux;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> aux;
		digits += aux;
	}
	cin >> s;
	long long int greatest = 0;
	for(int i = 0; i < digits.size()-s; i++) {
		long long int product = greatestProduct(digits.substr(i, s));
		if(product > greatest) greatest = product;
	} 
	cout << greatest << endl;
}