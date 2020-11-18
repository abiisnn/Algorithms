#include<bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {
	cout << n % 3 << endl;
    while(!(n % 3)) {
    	cout << n << endl;
        n /= 3;
    }
    cout << n << endl;
    if(n == 1) return true;
    return false;
}

int main() {
	int n; cin >> n;
	cout << isPowerOfThree(n) << endl;
}