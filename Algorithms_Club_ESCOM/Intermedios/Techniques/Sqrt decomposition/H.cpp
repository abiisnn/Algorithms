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
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, q;
	cin >> n;
	vector<lli> A(n);
	fore(i, 0, n) cin >> A[i];
	
	int len = (int)sqrt(n + .0) + 1;
	vector<vector<lli>> B(len);
	fore(i, 0, n) {
		B[i/len].pb(A[i]);
	}
	fore(i, 0, B.size()) {
		sort(B[i].begin(), B[i].end());
	}
	cin >> q;
	while(q--) {
		int opc;
		lli a, b, c;
		cin >> opc;
		if(opc) { // Opt 1: Change element pos a, to b
			cin >> a >> b; a--;
			int last = A[a]; // Actual value
			A[a] = b; // Change value
			int pos = a/len; // Pos of block
			fore(i, 0, B[pos].size()) { 
				if(B[pos][i] == last) {
					// Change element in the block
					B[pos][i] = b;
					break;
				}
			}
			// Sort block Array with the update
			sort(B[pos].begin(), B[pos].end());
		} else { // Opt 2:  Ans in range [l, r]
			cin >> a >> b >> c; a--, b--;
			int res = 0;
			for(int i = a; i <= b;) { // i begins in a, finish in b
				if(i % len == 0 && i + len - 1 <= b) {
					// Get answer of a complete block
					int index = lower_bound(B[i/len].begin(), B[i/len].end(), c) - B[i/len].begin(); 
					res += B[i/len].size() - index;
					i += len;
				} else {
					if(A[i] >= c) res++;
					i++;
				}
			}
			cout << res << endl;
		}
	}
}