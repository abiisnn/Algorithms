#include<bits/stdc++.h>
using namespace std;

bool isPal(int n) {
	string number = to_string(n);
	int i = 0, j = number.size()-1;
	bool ans = true;
	while(i < number.size()/2) {
		if(number[i] != number[j]) {
			ans = false;
			break;
		}
		i++, j--;
	}
	return ans;
}

int main() {
	int m = 0;
	for(int i = 100; i <= 999; i++) {
		for(int j = 100; j <= 999; j++) {
			if(isPal(i * j)) {
				if(i*j > m) {
					m = i *j;
				}
			}
		}
	}
	cout << m;
}