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
	lli w, n;
	cin >> w >> n;
	bool ans = true;
	set<int> s;
	for(int i = 2; i <= n; i++) {
		if(s.count(w % i)) {
			ans = false;
			break;
		}
		s.insert(w%i);
	}
	if (!ans) {
		cout << "No" << endl;
	} else cout << "Si" << endl;
}