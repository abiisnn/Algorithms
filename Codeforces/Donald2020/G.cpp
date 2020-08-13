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
#define MOD 1000000007
#define INF 500000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
bool comp(string a, string b) {
	fore(i, 0, min(int(a.size()), int(b.size()))) {
		if(a[i] > b[i]) return true;
		if(b[i] > a[i]) return false;
	}
	if(a.size() < b.size()) return true;
	return false;
}
int main() {
	optimizar_io
	int n; cin >> n;
	string aux;
	vector<int> bucket(10, 0);
	vector<string> v(n);
	fore(i, 0, n) {
		cin >> aux;
		sort(all(aux));
		reverse(all(aux));
		v[i] = aux;
	}
	sort(all(v), comp);
	fore(i, 0, n) cout << v[i];
	cout << endl;
}