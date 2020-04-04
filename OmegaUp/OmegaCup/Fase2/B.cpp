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
#define MAX 1000005
#define MOD 1000000007
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
bool geq(ld a, ld b){return a-b >= -eps;}

ld distancia(ld x2, ld x1, ld y2, ld y1) {
	return sqrt(((x2 - x1)*(x2 - x1)) + ((y2-y1) * (y2-y1)));
}

int main() {
	optimizar_io
	lli n, m;
	ld x, y;
	int l, k, q;
	cin >> n >> m >> l;
	vector<pair<ld, ld>> coor;
	fore(i, 0, 4) {
		cin >> x >> y;
		coor.pb(mk(x, y));
	}
	cin >> q;
	while(q--) {
		cin >> k; 
		vector<int> que(k);
		fore(i, 0, k) cin >> que[i];
		ld greater = 0;
		fore(i, 0, k) {
			for(int j = i+1; j < k; j++) {
				ld aux = distancia(coor[que[i]].fi, coor[que[j]].fi, coor[que[i]].se, coor[que[j]].se);
				if(geq(aux, greater)) {
					greater = aux;
				}
			}
		}
		cout << greater / 2 << endl;
	}

}