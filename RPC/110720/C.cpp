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
#define MAX 101
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int R, C, A, B; cin >> R >> C >> A >> B;
	vector<int> a(A), b(B);
	fore(i, 0, A) cin >> a[i];
	fore(i, 0, B) cin >> b[i];
	char matrix[R][C];

	int down = 0, right = 0;
	string c;
	fore(posA, 0, A) {
		right = 0;
		if(posA & 1) c = "WB";
		else c = "BW";
		int posP = 0;
		fore(posB, 0, B) {
			fore(i, down, down + a[posA]) {
				fore(j, right, right + b[posB]) {	
					matrix[i][j] = c[posP];
				}	
			}
			posP++;
			posP %= 2;
			right += b[posB];
		}
		down += a[posA];
	}
	fore(i, 0, R) {
		fore(j, 0, C) cout << matrix[i][j];
		cout << endl;
	}
}