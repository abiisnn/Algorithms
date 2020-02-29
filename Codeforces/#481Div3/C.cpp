#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

void giveAns(lli d, lli me, lli start){
	cout << d+1 << " " << me - start + 1 << endl;
}
int main() {
	optimizar_io
	lli n, m;

	cin >> n >> m;
	vector<lli> a(n, 0);
	vector<lli> b(m, 0);
	fore(i, 0, n) cin >> a[i];
	fore(i, 0, m) cin >> b[i];

	vector<lli> dormitory(n, 0);
	dormitory[0] = a[0];
	fore(i, 1, n) {
		dormitory[i] = dormitory[i -1] + a[i]; 
	}
	lli d = 0, r = 0;
	while((r < m) && (d < n)) {
		if(b[r] <= dormitory[d]) {
			giveAns(d, b[r], dormitory[d]-a[d]+1);
			r++;
		} else {
			d++;
		}
	}
}