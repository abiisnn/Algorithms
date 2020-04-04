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
#define MAX 105
#define MOD 1000000007 
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	int n, m;
	cin >> n >> m;
	string aux;
	vector<set<char>> bucket(m);
	fore(i, 0, n) {
		cin >> aux;
		for(int j = 0; j < aux.size(); j++) {
			bucket[j].insert(aux[j]);
		}
	}
	lli ans = 1;
	for(int i = 0; i < bucket.size(); i++) {
		ans = (ans * (bucket[i].size())) % MOD;
	}
	cout << ans << endl;
}