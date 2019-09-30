#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
	int tc, N, j, mex;
	vector<int> dp(100006, 0);
	vector<int> potencias = {1, 4, 27, 256, 3125, 46656};
	for(int i = 1; i <= 1e5; i++){
		unordered_set<int> nums;
		for(j = 0; j < potencias.size(); j++) {
			if(potencias[j] > i) break;
			nums.insert(dp[i-potencias[j]]);
		}
		mex = -1;
		for(j = 0; j < nums.size(); j++) {
			if(!nums.count(j)){
				mex = j;
				break;	
			} 
		}	
		if(mex == -1) mex = j;
		dp[i] = mex;
	}

	// for (auto &i : nombreset) {
	// 	cout << i << endl;
	// }
	cout << endl;
	cin >> tc;
	while(tc--) {
		cin >> N;
		vector<int> pi(N, 0);
		for(int i = 0; i < N; i++) 
			cin >> pi[i];
		int aux = 0;
		for(int i = 0; i < pi.size(); i++) {
			aux ^= dp[pi[i]];
		}
		if(aux) cout << "Gana el primer jugador."<< endl;
		else cout << "Gana el segundo jugador." << endl;
	}
	// for(int i = 2; i <= 100; i++) {

	// }
}