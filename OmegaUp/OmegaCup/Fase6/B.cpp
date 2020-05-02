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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	int n, aux;
	cin >> n;
	int ans = 0, best = 0;
	vector<vector<int>> matrix(n, vector<int>(0));
	for(int i = 0; i < n; i++) {
		best = 0;
		for(int j = 0; j < i+1; j++) {
			cin >> aux;
			matrix[i].pb(aux);
			if(aux > best) best = aux;
		}
		ans += best;
	}
	if(matrix[0][0] > 0) ans++;
	cout << ans << endl;
}