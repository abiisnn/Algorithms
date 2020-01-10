// https://codeforces.com/problemset/problem/1195/C
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 100002
#define optimizar_io ios_base::sync_with_stdio(0); 
typedef long long int lli;

lli mem[2][N];
lli numbers[2][N];


lli dp(int i, int j, int &n) {
	if((i < 0) or (i >= 2) ) return 0;
	if((j < 0) or (j >= n)) return 0;
	if(mem[i][j] != -1) return mem[i][j];

	lli take = 0;
	if(i == 0) take = numbers[i][j] + dp(i+1, j+1, n);
	else take = numbers[i][j] + dp(i-1, j+1, n); 
	lli noTake = dp(i, j+1, n);
	return mem[i][j] = max(take, noTake);
}
void clearMem() {
	for(int i = 0; i < 2; i++) 
		for(int j = 0; j < N; j++)
			mem[i][j] = -1;
}
int main() {
	cin.tie(0);
	int n;
	lli result;
	cin >> n;

	clearMem();
	for(int i = 0; i < 2; i++) 
		for(int j = 0; j < n; j++)
			cin >> numbers[i][j];
	
	result = dp(0, 0, n);
	result = max(result, dp(1, 0, n));
	cout << result << endl;
}
