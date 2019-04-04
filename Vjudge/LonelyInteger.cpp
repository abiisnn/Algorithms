// https://vjudge.net/contest/292248#problem/C
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int i, n, a, result;
	cin >> n;
	if(n == 1) 
		cout << n;
	else {
		cin >> a;
		result = a;
		for(i = 1; i < n; i++) {
			cin >> a;
			result = result xor a;
		}
		cout << result;
	}
	return 0;
}