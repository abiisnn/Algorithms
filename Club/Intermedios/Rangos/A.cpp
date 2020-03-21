#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 1000002
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> bit(MAX, 0);
void clean() {
	for(int i = 0; i < MAX; i++) bit[i] = 0;	
}
lli F(lli a, lli b){return a + b;}
void build() {
	for(int i = 1; i < bit.size(); i++) {
		int j = i + (i & -i);
		if(j < bit.size()) bit[j] = F(bit[j], bit[i]);
	}
}
void update(int i, lli val) {
	for(i++; i < bit.size(); i += i & -i) 
		bit[i] = F(bit[i], val);
}
lli query(int i) {
	lli ans = 0;
	for(i++; i; i -= i & -i) ans = F(ans, bit[i]);
	return ans;
}
int main() {
	optimizar_io
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<lli> num(n, 0);
		for(int i = 0; i < n; i++) cin >> num[i];
		clean();
		// On first element
		update(num[0], num[0]);
		lli ans = 0;
		for(int i = 1; i < n; i++) {
			ans += query(num[i] - 1);
			update(num[i], num[i]);
		}
		cout << ans << endl;
	}
}