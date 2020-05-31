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
#define MAX 37
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, m;
	cin >> n >> m;
	vector<string> names(n);
	set<string> query;
	string aux;
	fore(i, 0, n) cin >> names[i];
	fore(i, 0, m) {
		cin >> aux;
		query.insert(aux);
	}
	set<string> ans;
	fore(i, 0, n) {
		bool flag = true;
 		fore(j, 0, names[i].size()) {
			string prefix = names[i].substr(0, j+1);
			if(query.count(prefix)) {
				flag = false;
				break;
			}
		}
		if(flag) ans.insert(names[i]);
	}
	cout << ans.size() << endl;
	for(auto &i: ans) {
		cout << i << endl;
	}
}