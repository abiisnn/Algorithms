#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int lli;
using namespace std;

int main() {
	lli A, B, K, C;
	cin >> A >> B >> K >> C;
	if((C == A) || (C == B)) {
		if((C == A) & (C == B)) cout << K << endl;
		else {
			lli res = 1;
			for(int i = 1; i < K; i++) {
				res = (res * 2) % MOD; 
			}
			res = (res * K) % MOD;
			cout << res << endl;
		}	
	}
	else cout << "0" << endl;
}