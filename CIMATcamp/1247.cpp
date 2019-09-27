#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	int tc, ans;
	cin >> tc;
	while(tc--){
		cin >> n >> m;
		int array[n][m];
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++) {
				cin >> num;
				array[n][m]= num;
			}
		ans = array[0][0];
		for(int i = 1; i < n; i++) 
			for(int j = 1; j < m; j++) 
				ans = ans xor array[n][m];
		if(ans) cout << "Alice";
		else cout << "Bob";
	}
}