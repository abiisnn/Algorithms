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
#define MAX 500005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
struct comp {
  	bool operator() (const pair<int,int> &a, const pair<int, int> &b) const {
  		if(a.fi == b.fi) return a.se < b.se;
  		return a.fi > b.fi;
  	}
};

void solve(int n) {
	set<pair<int, int>, comp> s;  // pair: <size, index of L>
	vector<int> v(n);
	int i = 1;
	s.insert(mk(n, 0));
	while(s.size()) {
		auto point = s.begin();
		int L = (*point).se, R = L + (*point).fi-1;
		int mid = L + ((R - L) / 2);
		s.erase(point);
		v[mid] = i; i++;
		if(mid == L && mid == R) continue;
		s.insert(mk(R-mid, mid+1));
		if(mid == L) continue;	
		s.insert(mk(mid-L, L));
	}
	fore(i, 0, v.size()) cout << v[i] << " ";
	cout << endl;
}

int main() {
	int t, n; 
	cin >> t;
	while(t--) {
		cin >> n;
		solve(n);
	}
}