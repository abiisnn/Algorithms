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
#define N 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
char matrix[N][N];
void mark(int n, int m, int i, int j) {
	fore(h, 0, m) {
		if(matrix[i][h] != '1') matrix[i][h] = '-';
	}
	fore(h, 0, n) {
		if(matrix[h][j] != '1')matrix[h][j] = '-';
	}
}
void printM(int n, int m) {
	fore(i, 0, n) {
		fore(j, 0, m) cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void solve() {
	int n, m;  cin >> n >> m;
	fore(i, 0, n) {
		fore(j, 0, m) {
			cin >> matrix[i][j];
		}
	}
	fore(i, 0, n) {
		fore(j, 0, m) {
			if(matrix[i][j] == '1') {
				mark(n, m, i, j);
			}
		}
	}
	int cont = 0;
	fore(i, 0, n) {
		fore(j, 0, m) {
			if(matrix[i][j] == '0') {
				mark(n, m, i, j);
				cont++;
			}
		}
	}
	string name = "Vivek";
	if(cont & 1) name = "Ashish";
	cout << name << endl;
}
int main() {
	optimizar_io
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}