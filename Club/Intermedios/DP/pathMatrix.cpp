// https://practice.geeksforgeeks.org/problems/path-in-matrix/0
#include<bits/stdc++.h>
using namespace std;
int mem[22][22];
int matrix[22][22];

void fillMem() {
	for(int i = 0; i < 22; i++) 
		for(int j = 0; j < 22; j++)
			mem[i][j] = -1;
}
int dp(int r, int c, int n) {
	if(r >= n || r < 0) return -1;
	if(c >= n || c < 0) return -1;
 	if(r == (n-1)) return matrix[r][c];
	if(mem[r][c] != -1) return mem[r][c];
	return mem[r][c] = matrix[r][c] + max(dp(r+1, c, n), max(dp(r+1, c-1, n), dp(r+1, c+1, n)));
}
int main() {
	int tc, n, lastMax, currentMax, result;
	cin >> tc;
	while(tc--) {
		fillMem();
		cin >> n;
		for(int i = 0; i < n; i++)	
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		lastMax = 0;
		for(int j = 0; j < n; j++) {
			currentMax = dp(0, j, n);
			result = max(lastMax, currentMax);
			lastMax = result; 
		}	
		cout << lastMax << endl;
	}
	return 0;
}