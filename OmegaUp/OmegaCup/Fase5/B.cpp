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
#define MAX 1000000000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli dfs(vector<int> &volumen, vector<int> &calorias, int vol, int i) {
	if(i == volumen.size()-1) return calorias[i];
	
}
int main() {
	optimizar_io
	int s, a, v;
	while(cin >> s) {
		vector<int> volumen(s), calorias(s);
		fore(i, 0, s) {
			cin >> calorias[i] >> volumen[i];
		}
		cin >> a;
		vector<int> amigos(a);
		lli ans = 0;
		fore(i, 0, a) {
			cin >> v;
			lli d = dfs(volumen, calorias, v, 0);
			cout << "dfs en " << i << " es: "<< d << endl;
		}
		cout << ans << endl;

	}
}