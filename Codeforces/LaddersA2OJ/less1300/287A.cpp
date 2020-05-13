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
#define N 4
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

char matrix[N][N];

bool check(int i, int j, char color) {
	int cont = 0;
	if(matrix[i][j] == color) cont++;
	if(matrix[i][j+1] == color) cont++;
	if(matrix[i+1][j+1] == color) cont++;
	if(matrix[i+1][j] == color) cont++;
	if(cont >= 3)  return true;
	return false;
}

int main() {
	optimizar_io
	string str;
	fore(i, 0, N) {
		cin >> str;
		fore(j, 0, N) matrix[i][j] = str[j];
	}

	bool ans = false;
	fore(i, 0, N-1) {
		fore(j, 0, N-1) {
			if(check(i, j, '#') or check(i, j, '.')) {
				ans = true;
				break;
			} 
		}
	}
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}