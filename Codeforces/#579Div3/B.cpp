// https://codeforces.com/contest/1203/problem/B
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q, n, num;
	cin >> q;
	while(q--) {	
		cin >> n;
		vector<int> a(4*n, 0);
		map<int, int> bucket;
		for(int i = 0; i < (4*n); i++) {
			cin >> a[i];
			bucket[a[i]]++;
		}
		// Check all numbers has a quantity even
		bool allEven = true;
		for(auto &i : bucket) {
			if(i.second & 1) allEven = false;
		}
		sort(a.begin(), a.end());
		vector<lli> result;
		for(int i = 0, j = a.size()-1; i < (2*n); i++, j--) {
			result.pb(a[i] * a[j]);
		}
		sort(result.begin(), result.end());
		if((result[0] == result[result.size() - 1]) && allEven) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}