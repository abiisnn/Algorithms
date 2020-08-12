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
#define MAX 505
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;


int main() {
	optimizar_io
	int a, b, n, w, h; cin >> n >> w >> h;
	vector<pair<pair<int, int>, int>> v;
	set<pair<int, int>> aux;
	fore(i, 0, n) {
		cin >> a >> b;
		if(!aux.count(mk(a, b)) && w < a && h < b) {
			v.pb(mk(mk(a, b), i+1));
		}
		aux.insert(mk(a, b));
	}
	sort(all(v));
	set<int> waux, haux;
	int dif = 0;
	vector<int> pos;
	fore(i, 0, v.size()) {
		int actw = v[i].fi.fi, acth = v[i].fi.se;
		if(!waux.count(actw) && !haux.count(acth)) {
			dif++;
			pos.pb(v[i].se);
		}
		waux.insert(actw); haux.insert(acth);
	}
	cout << dif << endl;
	fore(i, 0, pos.size()) cout << pos[i] << " ";
	cout << endl;
	
}