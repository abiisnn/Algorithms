// https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int n, number, cont;
	cin >> n;
	vector<int> numbers(n, 0);
	vector<int> cubeta(101, 0);

	for(int i = 0; i < n ; i++) {
		cin >> number;
		numbers[i] = number;
	}
	for(int i = 0; i < n; i++) 
		cubeta[numbers[i]]++;
	cont = 0;
	for(int i = 0; i < cubeta.size(); i++) {
		if(cubeta[i] >= 2) {
			if((cubeta[i] % 2) == 0) number = cubeta[i] / 2;
			else {
				number = cubeta[i] - 1;
				number = cubeta[i] / 2;
			}
			cont += number;
		}
	}
	cout << cont;
}