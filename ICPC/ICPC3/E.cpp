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
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<vector<int>> bucket(MAX, vector<int>(0));
vector<lli> ans(MAX), v(MAX);

int main() {
	optimizar_io
	int n, b; cin >> n >> b;
	fore(i, 0, n) {
		cin >> v[i];
		if(v[i] != 0) bucket[v[i]].pb(i);
	}

	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < (int)bucket[i].size(); j++) {
			int index = bucket[i][j], l = (index + n - 1) % n, r = (index + 1) % n;
			lli here = 0;
			if(v[l] < v[index]) here = max(here, ans[l]);
			if(v[r] < v[index]) here = max(here, ans[r]);
			ans[index] = here + 1ll;
		}
	}
	fore(i, 0, n-1) cout << lli(ans[i]) * b << " ";
	cout << lli(ans[n-1]) * b << endl;
}
