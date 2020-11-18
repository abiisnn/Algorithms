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
#define MAX 200
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int b, r; cin >> b >> r;

	vector<int> heights(MAX);
	fore(i, 0, r) {
		int h, v, col;
		cin >> h >> v >> col;
		// checking:
		int greater = 0;
		fore(j, col, col + h) {
			greater = max(greater, heights[j]);
		}
		greater += v;
		fore(j, col, col + h) {
			heights[j] = greater;
		}
	}
	int greater = 0;
	fori(i, 0, b) {
		greater = max(greater, heights[i]);
	}
	cout << greater << endl;
}