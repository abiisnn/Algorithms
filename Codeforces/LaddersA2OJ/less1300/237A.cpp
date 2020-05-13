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
	int n, h, min; cin >> n;
	map<pair<int, int>, int> m;
	vector<pair<int, int>> times;
	fore(i, 0, n) {
		cin >> h >> min;
		m[mk(h, min)]++;
	}

	int ma = 0;
	for(auto &i: m) {
		if(i.se > ma) ma = i.se;
	}
	cout << ma << endl;
}