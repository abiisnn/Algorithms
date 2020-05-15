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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	fore(i, 0, m) cin >> v[i];

	sort(v.begin(), v.end());

	int best = 1005;
	for(int i = 0; i < m-n+1; i++) {
		int dif = v[i+n-1] - v[i];
		if(dif < best) best = dif;
	} 
	cout << best << endl;
}