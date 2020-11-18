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
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
 
void solve() {
	int n; cin >> n;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];

	vector<int> ans(n);
	queue<int> q;
 
	q.push(0);
	int i = 0;
	while(!q.empty()) {
		int lastGCD = q.front();
		q.pop();
		int bestGCD = -1, bestInd = 0;	
		for(int j = 0; j < n; j++) {
			if(v[j] && __gcd(lastGCD, v[j]) > bestGCD) {
				bestGCD = __gcd(lastGCD, v[j]);
				bestInd = j;					
			}			
		}
		if(bestGCD != -1) {
			ans[i] = v[bestInd];
			i++;
			v[bestInd] = 0;
			q.push(bestGCD);
		}
	}
	fore(i, 0, n) cout << ans[i] << " ";
	cout << endl;
}
 
int main() {
	int t; cin >> t;
	while(t--) solve();
}