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

char matrix[MAX][MAX];
bool visitados[MAX][MAX];
int N, M;
int dfs(int i, int j) {
	if(i >= N or j >= M) return 0;
	if(matrix[i][j] == '0') return 0;
	if(visitados[i][j]) return 0;
	visitados[i][j] = true;
	int ans = dfs(i+1, j) + dfs(i, j+1) + 1;
	return ans;
}

int main() {
	optimizar_io
	int tam;
	vector<int> ans;
	cin >> N >> M;
	fore(i, 0, MAX) {
		fore(j, 0, MAX) visitados[i][j] = false;
	}
	
	fore(i, 0, N) {
		string cad;
		cin >> cad;
		fore(j, 0, cad.size()) {
			matrix[i][j] = cad[j];
		}
	}
	
	int cont = 0;
	fore(i, 0, N) {
		fore(j, 0, M) {
			if(matrix[i][j] == 'X') {
				tam = dfs(i, j);
				if(tam > 0) ans.pb(tam);
			}
		}
	}
	sort(ans.begin(), ans.end());
	if(ans.size() > 0) {	
		cout << ans[ans.size()-1] << endl;
		cout << ans[0] << endl;
	} else cout << 0 << endl << 0 << endl;

}