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

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<lli> a(n, 0);
		fore(i, 0, n) cin >> a[i];
		if(n == 1) cout << "Yes" << endl;
		else {
			vector<bool> upper(n, false);
			vector<bool> lower(n, false);
			for(int i = 0; i < n; i++) {
				if(a[i] >= i) upper[i] = true;
				else break;
			}
			for(int i = 0, j = n-1; i < n; i++, j--) {
				if(a[j] >= i) lower[j] = true;
				else break;
			}
			int posUpper = -1, posLower = -1;
			for(int i = 0; i < n; i++) {
				if(!upper[i]) {
					posUpper = i;
					break;
				}
			}
			for(int i = 0; i < n; i++) {
				if(!lower[i]) {
					posLower = i;
					break;
				}
			}
			bool ans = false;
			if((posUpper == -1) or (posLower == -1)) ans = true;
		    else if((posUpper-1) >= 0) {
		    	if(lower[posUpper-1] && upper[posUpper-1]) ans = true;
		    } else if((posLower+1) < n) {
		    	if(lower[posLower+1] && upper[posLower+1]) ans = true;
		    }
			if(ans) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}	
}