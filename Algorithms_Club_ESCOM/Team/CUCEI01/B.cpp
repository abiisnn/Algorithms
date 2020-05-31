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
#define MAX 37
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

set<lli> getCombi(vector<lli> &v, int b, int c, int f) {
	set<lli> ans;
	fore(i, 0, f) {
		if(i == b or i == c) continue;
		ans.insert(v[i]);
		fore(j, i+1, f) {
			if(j == b or j== c) continue;
			ans.insert(v[i] + v[j]);
		}
	}
	return ans;
}	
int main() {
	optimizar_io
	int n; cin >> n;
	vector<lli> v(n);
	fore(i, 0, n) {
		cin >> v[i];
	} 
	sort(v.begin(), v.end());
	set<pair<pair<int, int>, int>> aux;
	for(int i = 0; i < v.size(); i++) {
		for(int j = i+1; j < v.size(); j++) {
			set<lli> comb = getCombi(v, i, j, v.size());
			int a = v[i], b = v[j];
			// cout <<"--->" <<v[i] << " " << v[j] << endl;
			for(auto &j: comb) {
				if(b > a && j > b) {
					pair<int, int> la = mk(a, b);
					aux.insert(mk(la, j));
					// cout << a << " " << b << " "<<j<< endl;
				}
			}
		}
	}
	for(auto j: aux) {
		cout << j.fi.fi << " "<< j.fi.se << " "<<j.se << endl;
	}
	// for(int i = 0; i < v.size()-2; i++) {
	// 	lli a = v[i], b = v[i+1];
	// 	set<lli> comb = getCombi(v, i+2, v.size());
	// 	for(auto &j: comb) {
	// 		if(b > a && j > b) {
	// 			cout << a << " " << b << " "<<j<< endl;
	// 		}
	// 	}
	// }
}