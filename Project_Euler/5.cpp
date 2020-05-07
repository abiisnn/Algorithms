#include<bits/stdc++.h>
using namespace std;

int main() {
	bool flag = true;
	int i = 1, num;
	while(flag) {
		num = 20 * i;
		bool ans = true;
		for(int j = 2; j <= 20; j++) {
			if((num % j) != 0) {
				ans = false; 
				break;
			}
		}
		if(ans) {
			cout << num << endl;
			flag = false;
			break;
		}
		i++;
	}
}