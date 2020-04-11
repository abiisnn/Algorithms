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
#define MAX 1000008
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> bit(MAX, 0);
void clean() { // O(MAX)
	for(int i = 0; i < MAX; i++) bit[i] = 0;	
}
lli F(lli a, lli b){return a + b;}

void build() {
	for(int i = 1; i < bit.size(); i++) {
		int j = i + (i & -i);
		if(j < bit.size()) bit[j] = F(bit[j], bit[i]);
	}
}
void update(int i, lli val) { // O(log(MAX))
	for(i++; i < bit.size(); i += i & -i) 
		bit[i] = F(bit[i], val);
}
lli query(int i) { // O(log(MAX))
	lli ans = 0;
	for(i++; i; i -= i & -i) ans = F(ans, bit[i]);
	return ans;
}
int main() {
	optimizar_io
	int index, k;
	int q, t, x;
	cin >> q;
	while(q--) {
		cin >> t >> x;
		if(t == 1) {
			update(x, 1);
		} else {
			cout << query(x) << endl;
		}
	}
	// update(index, k); // Sum k in index
	// query(r); // Sum of [0, r]
}
