#include<bits/stdc++.h>

using namespace std;
int gcd(int a, int b) {
	int r;
	while(b !=  0) r = a % b, a = b, b = r;
	return a;
}
int main() {
	int n, number, sum;
	int i, k;
	k = 0;
	cin >> n;
	while(n != 0) {
		k++;
		vector<int> v(n, 0);
		for(i = 0; i < n; i++) {
			cin >> number;
			v[i] = number;
		} 
		sum = 0;
		for(i = 0; i < n; i++) 
			sum += v[i];
		if(gcd(n, sum) != 0) {
			number = sum / n;
			sum = 0;
			for(i = 0; i < n; i++) {
				if(v[i] > number)
					sum += v[i] - number;
			}
		}
		else 
			sum = 0;
		cout << "Set #" << k << endl;
		cout << "The minimum number of moves is " << sum << "." << endl << endl;
		cin >> n;
	}
}