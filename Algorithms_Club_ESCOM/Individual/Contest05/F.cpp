#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MIN -1000000005
#define maxN 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<bool>visitados(maxN, false);
vector<lli> mem(maxN, 0);
vector<vector<int>> matrix;

lli dfs(int i, vector<lli> &A) {
	if(visitados[i]) return mem[i];
	visitados[i] = true;
	int index = 0;
	if(A[i] < 0) index = 1;
	vector<int>::iterator next = std::lower_bound(matrix[index].begin(), matrix[index].end(), i+1);
	lli ans = A[i];
	if(next != matrix[index].end()) {
		lli greater = MIN, aux = 0;
		for(int k = (next - matrix[index].begin()); k < matrix[index].size(); k++) {
			aux = dfs(matrix[index][k], A);
			if(aux > greater) {
				greater = aux;
			}
		}
		aux = greater + A[i];
		if(aux > A[i]) {
			ans = aux;
		} 
	}
	return mem[i] = ans;			
}

int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> A(n);
	vector<int> pos, neg;
	fore(i, 0, n) {
		cin >> A[i];
		if(A[i] > 0) pos.pb(i);
		else neg.pb(i);
	}
	matrix.pb(neg);
	matrix.pb(pos);
	lli sum = 0, ans = 0;
	// cout << "==================" << endl;
	fore(i, 0, n) {
		sum = dfs(i, A);
		if(sum > ans) ans = sum;
	}
	cout << ans << endl;
}