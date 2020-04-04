#include<bits/stdc++.h>
using namespace std;

using comp = ;
using poly = vector<int>;

// O(n^2)
poly multiply(const poly &A, const poly &B) {
	int m = A.size(), n = B.size();
	poly C(m + n - 1);
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			C[i + j] += A[i] * B[j];
		}
	}
	return C;
}
// O(n^2)
// Convolución lineal y circular
poly multiply2(poly &A, poly &B) {
	int m = A.size(), n = B.size();
	poly C(m + n - 1);
	A.resize(m + n - 1); // Siempre tener posiciones validas
	B.resize(m + n - 1);
	for(int k = 0; k < C.size(); ++k) {
		for(int i = 0; i <= k; ++i) {
			C[k] += A[i] * B[i-k];
		}
	}
	return C;
}
poly conv_circular(poly A, poly B) {
	assert(A.size() == B.size());
	int N = A.size();
	vector<comp> C(N);
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < N; ++i) {
			C[k] += A[i] * B[(k-i + N) % N];
		}
	}
	return C;

}

void fft(poly &A, int inv) {
	int N = A.size();
	comp w = polar(1.0, 2 * pi/ N);
	vector<comp> A_hat(N);
	for(int k = 0; k < N; ++k) {
		comp = ak = 0;
		for(int n = 0; n < N; ++n) {
			ak += pow(w, k*n *A[n]); 
		}
		if(inv == -1) {
			ak /= N;
		}
		A_hat[k] = ak;
	}
	A = A_hat;
}

void fft(poly &A, int inv) {
	int N = A.size();
	if(N == 1) return;
	comp w = polar(1.0, 2 * pi / N);
	vector<comp> A_even(N/2), A_odd(N/2);
	for(int i = 0; i < N; ++i) {
		if(i % 2 == 0) A_even.push_back(A[i]);
		else A_odd.push_back(A[i]);
	}
	fft(A_even, inv);
	fft(A_odd, inv);
	for(int k = 0; k < N; ++i) {
		A[k] = A_even[k] + pow(w, k) * A_odd[k];
		// w(k + N/2) = w^k * w^(N/2) = -w^k
		A[k + N/2] = A_even[k] - pow(w, k) * A_odd[k];
	}
	if(inv == -1) {
		for(int k = 0; k < N; ++K) {
			A[k] /= 2.0; // Funciona porque el numero de llamadas recursivas son log(N)
		}
	}
}
int nearestPowerOfTwo(int n) {
	int sz = 1;
	while(sz < n) sz <<= 1;
	return sz;
}

// Multiplicacion usando teorema de la convolucion // O(n log(n))
poly multiply3(poly &A, poly &B) {
	int m = A.size(), n = B.size();
	int sz = m + n - 1;
	int sz2 = nearestPowerOfTwo(sz);
	poly C(sz2);
	A.resize(sz2); // Siempre tener posiciones validas
	B.resize(sz2);
	fft(A, 1);
	fft(B, 1); // 1 significa DFT normal
	// Multiplicación punto a punto
	for(int i = 0; i < sz2; ++i) {
		C[i] = A[i] * B[i];
	}
	fft_inv(C, -1); // -1 significa la DFT inversa
	C.resize(sz);
	return C;
}
poly multiply4(poly A, poly B) {
	int m = A.size, n = B.size;
	int sz = m + n -1;
	poly C(sz);
	A.resize(sz);
	B.resize(sz);
	return conv_circular(A, B);
}
int main() {
	poly A = {3, 2, -5, 7};
	poly B = {4, 1, 3, 2};
	poly C_lineal = multiply(A, B);
	for(comp x: C_lineal) {
		cout << x << " ";
	} cout << endl;

	poly C_circular = conv_circular(A, B);
	for(comp x: C_circular) {
		cout << x << " ";
	} cout << endl;
	clock_t start = clock();
	// ....
	clock_t end = clock();
	cout << fixed << setprecision(3) << (double)(end-start) / CLOCKS_PER_SEC << endl;
	return 0;
}
