#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 300000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int split(vector<int> &v, int n) {
	int total = 0, last = -1;
	fore(i, 0, (int)v.size()) {
		if(last + 1 != v[i]) total++;
		last = v[i];
	}
	if(v[v.size()-1] != n-1) total++; 
	return total;
}
void solve() {
	int n; cin >> n;
	vector<vector<int>> matrix(n+1, vector<int>(0));
	fore(i, 0, n) {
		int num; cin >> num;
		matrix[num].pb(i);
	}
	int total = MAX;
	fore(i, 0, n+1) {
		if(matrix[i].size() >= 1) total = min(total, split(matrix[i], n));
	}
	cout << total << endl;
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}