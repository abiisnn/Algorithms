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
#define MAX 200002
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void solve() {
	vector<set<int>> boy(MAX), girl(MAX);
	fore(i, 0, MAX) boy[i] = {}, girl[i] = {};
	int a, b, k; cin >> a >> b >> k;

	vector<pair<int, int>> p(k, {0, 0});
	fore(i, 0, k) {
		int id; cin >> id;
		boy[id].insert(i);
		p[i].first = id;
	}
	fore(i, 0, k) {
		int id; cin >> id;
		girl[id].insert(i);
		p[i].second = id;
	}

	lli total = 0;
	int kaux = k;
	fore(i, 0, k) {
		set<int> aux = boy[p[i].first];
		aux.insert(all(girl[p[i].second]));
		
		total += (kaux - aux.size());
		boy[p[i].first].erase(i);
		girl[p[i].second].erase(i);
		kaux--;
	}
	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while(t--) solve();
}