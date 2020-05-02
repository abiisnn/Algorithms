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
#define MAX 101
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
char matrix[MAX][MAX];
bool checkColumn(pair<int, int> &a, int i , int j, int &n) {
	int bolitas = 0, x = 0;;
	for(int I = i; I < n; I++) {
		if(matrix[I][j] == 'O') bolitas++; 
		else if(matrix[I][j] == '.'){
			a.fi = I;
			a.se = j;
		} else x++;
		if(bolitas >= 4 && (x == 0) && (bolitas - (I - i) + 1== 1)) return true;
	}
	return false;
}
bool checkRow(pair<int, int> &a, int i , int j, int &n) {
	int bolitas = 0, x = 0;
	for(int J = j; J < n; J++) {
		if(matrix[i][J] == 'O') bolitas++;
		else if(matrix[i][J] == '.'){
			a.fi = i;
			a.se = J;
		} else x++;
		if(bolitas >= 4 && (bolitas - (J - j) + 1 == 1) && x == 0) return true;
	}
	return false;
}
bool diagonal(pair<int, int> &a, int i , int j, int &n) {
	int bolitas = 0;
	int avanzo = 0, x = 0;;
	for(int I = i, J = j; I < n; I++,J++) {
		// cout << I<< " " << J << " bolitas: " << bolitas << endl;
		if(matrix[I][J] == 'O') bolitas++;
		else if(matrix[I][J] == '.'){
			a.fi = I;
			a.se = J;
		} else x++;
		if((x == 0) && bolitas >= 4 && (bolitas - avanzo+ 1 == 1)) return true;
		avanzo++;
	}
	return false;
}
int main() {
	optimizar_io
	int n; cin >> n;
	int q; cin >> q;
	int x, y, t;
	fore(i, 0, MAX) {
		fore(j, 0, MAX) {
			matrix[i][j] = '.';
		}
	}
	fore(i, 0, q) {
		cin >> x >> y >> t; 
		if(t) matrix[x-1][y-1] = 'X';
		else matrix[x-1][y-1] = 'O'; 
	}
	// fore(i, 0, n) {
	// 	fore(j, 0, n) {
	// 		cout << char(matrix[i][j]) << " ";
	// 	} cout << endl;
	// }
	vector<int> columns(n), rows(n);
	set<pair<int, int>> ans;
	fore(i, 0, n) {
		fore(j, 0, n) {
			pair<int, int> aux;
			if(checkColumn(aux, i, j, n)) {
				ans.insert(aux);
			} 
			if(checkRow(aux, i, j, n)) {
				ans.insert(aux);
			}
			if(diagonal(aux, i, j, n)) {
				ans.insert(aux);
			}
		}
	}
	for(auto &i: ans) {
		cout << i.first+1 << " " << i.second +1<< endl;
	}
}