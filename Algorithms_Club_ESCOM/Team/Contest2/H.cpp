#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 64
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

set<ulli> sheldonNumbers;
void setBit(ulli &var, int i) {
	var = var | (1 << i);
}
void createSheldon(int k, int m, int n) { // 1^n (0^m 1^n)^k 
	ulli sheldon = 0;
	int aux = 0;
	for(int i = 0; i < k; i++) {
		aux = i * (m+n);
		for(int posN = aux; posN < aux + n; posN++) setBit(sheldon, posN);
	}
	aux += (n+m)-1;
	for(int i = 0; i < n; i++) setBit(sheldon, ++aux);
	sheldonNumbers.insert(sheldon);
} 
// (1^n 0^m)^k && (0^m 1^n)^k
void createSheldon2(int k, int m, int n) {
	ulli sheldon = 0;
	for(int i = 0; i < k; i++) {
		int a = (i+1) * (m+n);
		for(int j = a-n; j < a; j++) {
			setBit(sheldon, j);
		}
	}
	sheldonNumbers.insert(sheldon);

	// // (0^m 1^n)^k 
	// sheldon = 0;
	// int aux = 0;
	// for(int i = 0; i < k; i++) {
	// 	aux = i * (m+n);
	// 	for(int posN = aux; posN < aux + n; posN++) setBit(sheldon, posN);
	// }
	// sheldonNumbers.insert(sheldon);
}
void createSheldon3(int k, int m, int n) {
	// 1^n (0^m 1^n)^k 0^m
	ulli sheldon = 0;
	int aux = 0;
	for(int i = 0; i < k; i++) {
		aux = (i * (m+n)) + m;
		for(int posN = aux; posN < aux + n; posN++) setBit(sheldon, posN);
	}
	aux = (k * (m+n)) + m;
	for(int i = 0; i < n; i++) {
		setBit(sheldon, aux);
		aux++;
	}
	sheldonNumbers.insert(sheldon);	
}
void generate() {
	// 1^n (0^m 1^n)^k 
	for(int i = 1; i <= MAX; i++) {
		for(int j = 0; j <= MAX; j++) {
			int k = 0;
			while((i + (k * (j+i))) < MAX) {
				createSheldon(k, j, i); 
				k++;
			}
		}
	}
	// (1^n 0^m)^k 
	for(int n = 1; n <= MAX; n++) {
		for(int m = 0; m <= MAX; m++) {
			int k = 0;
			while(k*(n+m) < MAX) {
				createSheldon2(k, m, n);
				k++;
			}
		}	
	}
	// 1^n (0^m 1^n)^k 0^m
	for(int n = 1; n <= MAX; n++) {
		for(int m = 0; m <= MAX; m++) {
			int k = 0;
			while(n + (k*(n+m)) + m < MAX) {
				createSheldon3(k, m, n);
				k++;
			}
		}	
	}
	
	for(int i = 0; i <= MAX; i++) {
		ulli sheldon = 0;
		for(int j = 0; j < i; j++) {
			setBit(sheldon, j);
		}
		sheldonNumbers.insert(sheldon);
	}
}
int main() {
	optimizar_io
	ulli x, y;
	cin >> x >> y;
	generate();
	
	// cout << sheldonNumbers.size() << endl;
	// for(auto &i: sheldonNumbers) {
	// 	cout << i << " ";
	// } cout << endl;
	int ans = 0;
	for(auto &i: sheldonNumbers) {
		if((i >= x) && (i <= y)) ans++;
	}
	cout << ans << endl;
}