#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	lli t, n, m, k;
	string a, b;
 
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		cin >> a >> b;
		set<pair<char, char>> pairs;
		// Getting pairs
		for(int i = 0; i < (a.size() - k + 1); i++) {
			pairs.insert(make_pair(a[i], a[i + k - 1]));
		}	
		lli res = 0;
		for(auto const &x : pairs) {
			vector<int> counter(26, 0);
			for(int i = 0; i < b.size(); i++) {
				// Adding to bucket	
				counter[b[i] - 97]++;
				if((b[i]) == (x.second)) {
					res += counter[x.first - 97];
				}
			}
		}
		cout << res << endl;
	}	
}