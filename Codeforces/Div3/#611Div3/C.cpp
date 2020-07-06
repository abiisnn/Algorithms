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
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, cont = 0; 
	cin >> n;
	vector<int> f(n+1), options, v;
	set<int> has, nohas, aux;
	fori(i, 1, n) {
		cin >> f[i];
		if(f[i]) has.insert(f[i]), cont++;
		else nohas.insert(i);
	}
	fori(i, 1, n) {
		if(!has.count(i)) options.pb(i), aux.insert(i);
	}
	for(auto &i: nohas) if(aux.count(i)) v.pb(i);
	for(auto &i: nohas) if(!aux.count(i)) v.pb(i);

	vector<bool> isUsed(options.size(), false);
	int i = 0, j = 0;
	while(cont < n) {
		if(!isUsed[j] && options[j] != v[i]) {
			f[v[i]] = options[j];
			isUsed[j] = true;
			i++; 
			cont++;
		}
		j++;
		j %= options.size();
	}
	fori(i, 1, n) cout << f[i] << " ";
	cout << endl;
}