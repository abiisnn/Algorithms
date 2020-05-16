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

int main() {
	optimizar_io
	int t;
	cin >> t;
	while(t--) {
		string str;
		vector<string> matrix(9, "");
		fore(i, 0, 9) {
			cin >> matrix[i];
		}
		matrix[0][6] = matrix[0][5];
		matrix[1][1] = matrix[1][0];
		matrix[2][5] = matrix[3][5];
		matrix[3][8] = matrix[2][8];	
		matrix[4][2] = matrix[4][0];
		matrix[5][4] = matrix[6][4];
		matrix[6][7] = matrix[6][6];
		matrix[7][0] = matrix[7][1];
		matrix[8][3] = matrix[8][2];
		fore(i, 0, 9) {
			cout << matrix[i] << endl;
		}
	}
}