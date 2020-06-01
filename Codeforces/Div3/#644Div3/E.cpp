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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
bool check(vector<string> &matrix, int i, int j) {
	bool a = true, b = true;
	if(i+1 < matrix.size()) {
		if(matrix[i+1][j] != '1') a = false;
	}
	if(j+1 < matrix.size()) {
		if(matrix[i][j+1] != '1') b = false;
	}
	return a || b;
}
int main() {
	optimizar_io
	int t, n; cin >> t;
	while(t--) {
		cin >> n;
		string m;
		vector<string> matrix;
		fore(i, 0, n) { 
			cin >> m;
			matrix.pb(m);
		}
		bool flag = true;
		fore(i, 0, n) {
			fore(j, 0, n) {
				if(matrix[i][j] == '1') {
					if(check(matrix, i, j)) continue;
					else {
						flag = false;
						break;
					} 
				}
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}