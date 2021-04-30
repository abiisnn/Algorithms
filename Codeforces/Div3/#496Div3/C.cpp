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
#define MAX 45
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	vector<lli> pow(MAX);
	pow[0] = 1ll, pow[1] = 2ll;
	fore(i, 2, MAX) pow[i] = pow[i-1] * 2ll;

	int n; cin >> n;
	vector<lli> v(n);
	fore(i, 0, n) cin >> v[i];
	
	map<lli, int> bucket;
	fore(i, 0, n) bucket[v[i]]++;

	set<lli> yes;
	fore(i, 0, n) {
		fore(j, 0, MAX) { // probando
			lli need = pow[j] - v[i];
			int exist = bucket[need];
			if(need == v[i] && exist >= 2) { // need more than 2
				yes.insert(need);
			} else if(need != v[i] && exist >= 1) {
				yes.insert(need);
				yes.insert(v[i]);
			}
		}		
	}

	int remove = 0;
	fore(i, 0, n) {
		if(yes.count(v[i]) == 0) remove++;
	}
	cout << remove << endl;

}