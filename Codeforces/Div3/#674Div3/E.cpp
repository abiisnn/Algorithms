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
#define MAX 1000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli tryOption(lli a0, lli a1, lli a2, lli b0, lli b1, lli b2) {
	return min(a0, b1) + min(a1, b2) + min(a2, b0);
}
int main() {
	optimizar_io
	lli n; cin >> n;
	vector<lli> A(3), B(3);
	fore(i, 0, 3) cin >> A[i];
	fore(i, 0, 3) cin >> B[i];
	vector<pair<int, int>> v = {{0, 0}, {1, 1}, {2, 2}, {0, 2}, {1, 0}, {2, 1}};
	sort(all(v));
	lli bestAli = tryOption(A[0], A[1], A[2], B[0], B[1], B[2]); 
	lli bestAns = MAX;
	do {
		vector<lli> a = A, b = B;
		for(int i = 0; i < (int)v.size(); i++) {
			lli get = min(a[v[i].first], b[v[i].second]);
			a[v[i].first] -= get;
			b[v[i].second] -= get;
		}	
		lli current = tryOption(a[0], a[1], a[2], b[0], b[1], b[2]);
		bestAns = min(bestAns, current);
	} while(next_permutation(all(v)));

	cout << bestAns << " " << bestAli << endl;
}