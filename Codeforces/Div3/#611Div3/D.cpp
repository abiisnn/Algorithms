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
#define MAX 60
#define INF 3ll * 1e9
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, m; cin >> n >> m;
	vector<lli> tree(n);
	set<lli> places, t;
	fore(i, 0, n) cin >> tree[i], t.insert(tree[i]);
	
	sort(all(tree));

	cout << "Arboles:" << endl;
	fore(i, 0, n) cout << tree[i] << " ";
	cout << endl;

	fore(i, 0, n) {
		lli l = tree[i] - 1;
		lli r = tree[i] + 1;
		if(!places.count(l) && !t.count(l)) {
			places.insert(l);
		}
		if(!places.count(r) && !t.count(r)) {
			places.insert(r);
		}
	}

	// Create set ans, pair: difference, treeindex
	lli best = 0;
	set<pair<lli, int>> sder, sizq;
	fore(i, 0, n) {
		lli dif = INF;
		// Izquierda
		lli next = tree[i]-1;
		if(next >= izq[i]) {
			dif = 1ll;
		}
		sizq.insert(mk(dif, i));
		dif = INF;
		next = tree[i] + 1;
		if(next <= der[i]) {
			dif = 1ll;
		}
		sder.insert(mk(dif, i));
	}
	cout << "derecha: " << endl;
	for(auto &i: sder) {
		cout <<i.fi << " " << i.se << endl;
	}
	cout << "i<quierda: " << endl;
	for(auto &i: sizq) {
		cout <<i.fi << " " << i.se << endl;
	}

}

