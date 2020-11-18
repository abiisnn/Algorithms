#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 0
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<int> mem(MAX, -1);

int dp(vector<lli> &A, vector<lli> &B, int n, int m, int i, int j, lli k) {
	cout << "i: " << i << endl;
	if(i >= n && i >= m) {return -1;}
	if(k < 0) {return -1;}
	if(k == 0) return 0;
	if(mem[i] != -1) return mem[i];  
	int opcA = dp(A, B, n, m, i+1, k-A[i]);
	int opcB = dp(A, B, n, m, i+1, k-B[i]);

	return mem[i] = 1 + std::max(opcA, opcB);
}
int main() {
	optimizar_io
	int n, m;
	lli k; cin >> n >> m >> k;
	vector<lli> A(n), B(m);
	fore(i, 0, n) cin >> A[i];
	fore(i, 0, m) cin >> B[i];
	cout << "HOLA" << endl;
	int ans = dp(A, B, n, m, 0, 0, k);
}