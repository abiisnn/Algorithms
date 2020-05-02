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
#define MAX 301
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<vector<int>> bus;
int n, m;
int busqueda(int i, int j, char dir) {
	if(i == (n-1) && j == (m-1)) return 1;
	if(i >= n or j >= m) return 0;
	if(i < 0 or j < 0) return 0;
	char newDir = dir;
	if(bus[i][j] == 0) {
		if(dir == 'N') i -= 1;
		if(dir == 'E') j += 1;
		if(dir == 'S') i += 1;
		if(dir == 'O') j -= 1;
	} else if(bus[i][j] == 1) {
		if(dir == 'N') {
			newDir = 'E';
			j += 1;
		} else if(dir == 'E') {
			newDir = 'S';
			i += 1;
		} else if(dir == 'S') {
			newDir = 'O';
			j -= 1;
		} else if(dir == 'O') {
			newDir = 'N';
			i -= 1;
		}
	} else if(bus[i][j] == 2) {
		if(dir == 'N') {
			newDir = 'O';
			j -= 1;
		} else if(dir == 'E') {
			newDir = 'N';
			i -= 1;
		} else if(dir == 'S') {
			newDir = 'E';
			j += 1;
		} else if(dir == 'O') {
			newDir = 'S';
			i += 1;
		}
	} else {
		if(dir == 'N') {
			newDir = 'S';
			i += 1;
		} else if(dir == 'E') {
			newDir = 'O';
			j -= 1;
		} else if(dir == 'S') {
			newDir = 'N';
			i -= 1;
		} else if(dir == 'O') {
			newDir = 'E';
			j += 1;
		}
	}
	return busqueda(i, j, newDir);
}

int main() {
	optimizar_io
	cin >> n >> m;

	fore(i, 0, n) {
		vector<int> aux(m, 0);
		bus.pb(aux);
	}
	fore(i, 0, n) {
		fore(j, 0, m) {
			cin >> bus[i][j];
		}
	}
	
	int ans = busqueda(0, 0, 'E');
	if(ans) cout << "llegaste" << endl;
	else cout << "te perdiste" << endl; 

}