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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, ele; cin >> n;
	vector<int> a(n), c(n);
	multiset<int> pos;
	fore(i, 0, n) cin >> a[i];
	fore(i, 0, n) {
		cin >> ele;
		pos.insert(ele);
	}
	for(int i = 0; i < n; i++) {
		int need = n - a[i];
		multiset<int>::iterator it = pos.lower_bound(need);
		if(it != pos.end()) {
			c[i] = (a[i] + (*it)) % n;
			pos.erase(it);
		} else {
			c[i] = (a[i] + (*pos.begin())) % n;
			pos.erase(pos.begin());
		}
	}
	fore(i, 0, n) cout << c[i] << " ";
	cout << endl;
}