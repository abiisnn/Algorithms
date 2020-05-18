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

void solve() {
	int N, dad, q, c, aux = 2;
	cin >> N;
	vector<vector<pair<int, int>>> nodos(N+1, vector<pair<int, int>>(0));
	fore(i, 0, N-1) {
		cin >> dad >> c;
		nodos[dad].pb(mk(aux, c));
		aux++;
	}

	vector<lli> anterior(N+1, 0);
	fori(i, 1, N) {
		int menor = MAX;
		fore(j, 0, nodos[i].size()) {
			if(nodos[i][j].se < menor) menor = nodos[i][j].se;
		}
		if(menor == MAX) continue;

		fore(j, 0, nodos[i].size()) {
			c = nodos[i][j].se;
			lli res = c;
			if(menor != c) {
				res = menor + 2LL * (c - menor);
			}
			res += anterior[i]; // Lo que lleva acumulado en mi padre
			anterior[nodos[i][j].fi] = res; // anterior[yo]
		}	
	}
	vector<lli> v;
	lli maxSeg = 0;
	fori(i, 1, N) {
		if(nodos[i].size()) continue;
		v.pb(anterior[i]); // Es nodo hoja
		if(anterior[i] > maxSeg) maxSeg = anterior[i];
	}
	sort(v.begin(), v.end());

	cin >> q;
	lli seg;
	while(q--) {
		cin >> seg;
		vector<lli>::iterator upper = std::upper_bound(v.begin(), v.end(), seg);
	    if(upper != v.end()) {
	    	int posAns = upper - v.begin();
    		if(posAns) cout << posAns<<endl;
    		else cout << 0<< endl;
	    } else {
	    	if(seg >= maxSeg) cout << v.size() << endl;
	    	else cout << 0 << endl;
	    }
	}
}

int main() {
	optimizar_io
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}