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
#define MAX 50
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<lli> pot(MAX, 0);

lli solve(lli n) {
	cout << "---------" << n << endl;
	lli ans = 0;
	for(int i = 0; pot[i] <= n; i++) {
		lli mul = (n / (pot[i]*2));
		// if(i == 0 && (n & 1)) mul++;
		if((n % (pot[i]*2)) != 0) mul = n / (pot[i]*2) +1;
		if(i & 1) mul--;
		cout << "i: " << i << " " <<pot[i] << " mul:" << mul << endl; 
		ans += (pot[i] * mul);
	}
	cout << "ans: " << ans << endl;
	return ans;
}
int main() {
	optimizar_io
	pot[0] = 1, pot[1] = 2;
	lli d = 2;
	for(lli i = 2; i < 50; i++) {
		pot[i] = pot[i-1] * d;
	}
	int q;
	lli a, b;
	cin >> q;
	while(q--) {
		cin >> a >> b;
		lli A = solve(a-1);
		lli B = solve(b);
		cout << "acum en a: "<< A << endl;
		cout << "acum en b: "<<B<< endl;
		cout << B - A << endl;
	}
}