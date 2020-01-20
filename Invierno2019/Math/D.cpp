#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define FOR(i, n) for(int i = 0; i < n; i++)
typedef long long int lli;
typedef pair<int, int> pii;
 
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	lli n, k;
	cin >> n >> k;
	vector<lli> c(n, 0);
	
	for(int i = 0; i < n; i++) 
		cin >> c[i];
 
	lli L = 1;
	for(int i = 0; i < n; i++) {
		L = (L * ((c[i] / __gcd(L, c[i])) % k)) % k;
	}
	if(L) cout << "No" << endl;
	else cout << "Yes" << endl;
}