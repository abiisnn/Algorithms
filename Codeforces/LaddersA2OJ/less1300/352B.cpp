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

int check(vector<int> &vec) {
	if(vec.size() == 1) return 0;
	
	sort(vec.begin(), vec.end());
	if(vec.size() == 2) return vec[1] - vec[0];
	int lastDif = vec[1] - vec[0];
	for(int i = 2; i < vec.size(); i++) {
		if(vec[i] - vec[i-1] != lastDif) return -1;
	}
	return lastDif;
}
int main() {
	optimizar_io
	int n, aux;
	cin >> n;
	map<int, vector<int>> m;
	
	fore(i, 0, n) {
		cin >> aux;
		m[aux].pb(i);
	}
	vector<pair<int, int>> ans;
	for(auto &i: m) {
		int dif = check(i.se);
		if(dif != -1) ans.pb(mk(i.fi, dif));
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].fi << " " << ans[i].se << endl;
	}
}