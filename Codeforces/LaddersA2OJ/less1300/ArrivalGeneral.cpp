// https://codeforces.com/problemset/problem/144/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, nMin, nMax, posMin, posMax;
	cin >> n;
	vector<int> numbers(n, 0);
	for(int i = 0; i < n; i++) cin >> numbers[i];

	nMin = 105, nMax = 0;
	for(int i = 0; i < n; i++) {
		if(numbers[i] > nMax) nMax = numbers[i];
		if(numbers[i] < nMin) nMin = numbers[i];
	} 	

	// Searching pos max
	posMax = 0;	
	for(int i = 0; i < n; i++) {
		if(numbers[i] == nMax) {
			posMax = i;
			break;
		}
	}
	// Searching pos min
	posMin = 0;
	for(int i = n - 1; i >= 0 ; i--) {
		if(numbers[i] == nMin) {
			posMin = i;
			break;
		}
	}
	if(posMax > posMin) n = posMax + n -1 - posMin - 1; 
	else n = posMax + n - 1 - posMin; 
	cout << n << endl;
}