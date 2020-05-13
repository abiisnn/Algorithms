#include<bits/stdc++.h>
#define N 20
using namespace std;
typedef long long int lli;
vector<vector<int>> matrix(N, vector<int>(N));

lli max(lli a, lli b) {
	if(a > b) return a;
	return b;
}
lli right(int i, int j, int k) {
	if(j+k-1 < N) {
		lli ans = 1;
		for(int l = 0; l < k; l++) {
			ans *= matrix[i][j+l];
		}
		return ans;
	}
	return -1;
}
lli diagonal(int i, int j, int k) {
	lli best = 0;
	if(i+k-1 < N && j+k-1 < N) {
		lli ans = 1;
		for(int l = 0; l < k; l++) {
			ans *= matrix[i+l][j+l];
		}
		if(ans > best) best = ans;
	}
	if(i-k+1 >= 0 && j+k-1 < N) {
		lli ans = 1;
		for(int l = 0; l < k; l++) {
			ans *= matrix[i-l][j+l];
		}
		if(ans > best) best = ans;
	}

	return best;
}
lli down(int i, int j, int k) {
	if(i+k-1 < N) {
		lli ans = 1;
		for(int l = 0; l < k; l++) {
			ans *= matrix[i+l][j];
		}
		return ans;
	}
	return -1;
}

lli check(int i, int j, int k) {
	return max(right(i, j, k), max(diagonal(i, j, k), down(i, j, k)));
}

int main() {
	string num;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> num;
			int aux;
			std::istringstream(num) >> aux;
			matrix[i][j] = aux;
		}
	}
	
	int k = 4;
	lli greatest = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			lli product = check(i, j, k);
			if(product > greatest) greatest = product; 
		}
	}
	cout << greatest << endl;
}