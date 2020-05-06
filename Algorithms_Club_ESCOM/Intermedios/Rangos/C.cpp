#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;
int l[MX], r[MX], res[MX], ult[MX];
vector<int> pos[MX];

int main() {
	optimizar_io
	int n, q;
	cin >> n;
	fori(i, 1, n) cin >> a[i];
	cin >> q
	fori(i, 1, 100000) ult[i] = -1;
	fori(i, 1, q) {
		cin >> l[i] >> r[i];
		pos[r[i]].pb(i);
	}
	for(int i = 1; i <= n; i++) {
		if(ult[a[i]] != -1) 
			update(ult[a[i]], -1);
		update(i, 1);
		ult[a[i]] = i;
		fore(j, 0, pos[i].size()) {
			int ind = pos[i][j];
			res[ind] = query(l[ind], r[ind]);
		}
	}
	fori(i, 1, q) cout << res[i] << endl;
}