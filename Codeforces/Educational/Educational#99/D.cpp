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
#define AUX 10000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

bool isSorted(vector<int> &v) {
	bool sorted = true;
	fore(i, 0, (int)v.size()-1) {
		if(v[i+1] < v[i]) sorted = false;
	}
	return sorted;
}
void solve() {
	int n, x; cin >> n >> x;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];
	
	int total = 0;
	for(int i = 0; i < n; i++) {
		if(isSorted(v)) break;
		while(i < n && v[i] > x) {
			swap(v[i], x);
			total++;
			i++;
		}
	}
	
	if(!isSorted(v)) total = -1;
	cout << total << endl;
}

int main() {
	int t; cin >> t;
	while(t--) solve();
}