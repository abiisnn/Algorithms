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
ld eps = 1e-6;

int main() {
	int t, p;
	cin >> t >> p;
	vector<ld> teams(t-1), problems(p);
	fore(i, 0, t-1) cin >> teams[i];
	fore(i, 0, p) cin >> problems[i];
	char matrix[t][p];
	int problemasYo = 0;
	fore(i, 0, t) {
		fore(j, 0, p) {
			cin >> matrix[i][j];
		}
	}
	vector<int> totales;
	fore(i, 0, t-1) {
		ld prob = 1;
		fore(j, 0, p) {
			if(matrix[i][j] == '?') 
				prob *= (teams[i]*problems[j]);
		}
		if(prob != 1)
			totales.pb((1-prob));
	}
	ld ans = 1;
	fore(i, 0, totales.size()) {
		ans *= totales[i];
	}
	cout << ans / totales.size()<< endl;
}