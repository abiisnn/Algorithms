#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define n 2
typedef long long int lli;
typedef vector<vector<lli>> matrix;

matrix iden(lli m) {
	matrix id;
	id.assign(m, vector<lli>(m, 0));
	for(int i = 0; i < m; i++) 
		id[i][i] = 1;
	return id;
}
matrix mul(matrix &A, matrix &B) {
	matrix c;
	c.assign(n, vector<lli>(n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				c[i][j] = (((A[i][k] * B[k][j]) % MOD) + c[i][j])  % MOD;
			}
		}
	}
	return c;
}

matrix binPow(matrix b, lli p) {
	matrix res = iden(2);
	while(p) {
		if(p & 1ll) res = mul(res, b);
		p >>= 1l;
		b = mul(b, b);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	lli k;
	cin >> k;

	// Create Matrix A
	matrix A;
	A.assign(2, vector<lli>(2, 0));
	int aux[4] = {3, 8, 1, 3};
	int cont = 0;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			A[i][j] = aux[cont];
			cont++;
		}
	}

	// Create base
	matrix B;
	B.assign(2, vector<lli>(1, 0));
	B[0][0] = 3; B[1][0] = 1;

	// A ^ (k -1)
	A = binPow(A, k-1ll);

	lli y = (A[1][0] * 3) % MOD;
	y = (y + A[1][1]) % MOD;
	y = (y * y) % MOD;
	cout << y << endl;
}