#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int n, i;
	cin >> n;
	int array[n];

	for(i = 0; i < n; i++)
		cin >> array[i];

	for(i = n-1; i >= 0; i--) 
		cout << array[i] << " ";
	return 0;
}