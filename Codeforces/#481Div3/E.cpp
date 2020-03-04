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

int main() {
	optimizar_io
	int n;
	lli w, l, r, lAns, rAns;
	cin >> n >> w;

	vector<int> a(n, 0);
	fore(i, 0, n) cin >> a[i];
	
	lAns = 0, rAns = w;
	l = 0, r = w;
	fore(i, 0, n) {
		l += a[i];
		r += a[i];
		lAns = max(l, lAns);
		rAns = min(r, rAns);
	}
	if(lAns > rAns) cout << "0" << endl;
	else cout << rAns - lAns + 1 << endl;
}