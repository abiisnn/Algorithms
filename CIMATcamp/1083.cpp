#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	int k, l, m, rocks;
	cin >> k >> l >> m;
	for(int i = 0; i < m; i++) {
		cin >> rocks;
		vector<bool> dp(rocks, false);
		for(int j = 0; j < rocks; j++) {
			if(!dp[j-1] or (j>=k and !dp[j-k]) or (j>=l and !dp[j-l]))
				dp[j] = true;
		}	
		cout << "------- k: " << k << " l: " << l << endl;
		for(int j = 0; j < rocks; j++) {
			if(dp[j]) cout << "N ";
			else cout << "P";
		}
		cout << endl;
	}
	return 0;
}