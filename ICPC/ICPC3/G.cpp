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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

struct triplet {
	lli g;
	int a, b;
};

vector<lli> mem(MAX, -1);
vector<triplet> v;

lli dp(int curr) {
	if(mem[curr] != -1) return mem[curr];

	// two options

	lli best = 0;
	for(int i = 0; i < ) {
		lli dpHere = v[curr].g + dp(curr+i);
		best = max(best, dpHere);
	}

	lli op2 = dp(curr + 1);

}

int main() {
	optimizar_io
	int n; cin >> n;
	lli g;
	int a, b; 
	for(int i = 0; i < n; i++) {
		cin >> g >> a >> b;
		v.pb({g, a, b});
	}

	cout << dp(0) << endl;
}