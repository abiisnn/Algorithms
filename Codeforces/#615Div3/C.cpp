#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 10000005
typedef long long int lli;

int isPrime(lli &n) {
	cout << "--------number: " << n << endl;
	lli limit = sqrt(n);
	int ans = 0;
	int i = 0; 
	for(i = 2; i <= limit; i++) {
		if((n % i) == 0) {
			ans = i; 
		}
	}
	cout << "ans: " << ans << endl;
	return ans;
}

void find(lli n) {
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	lli n, total, ans;
	cin >> t;
	while(t--) {
		cin >> n;
		find(n);	
	}
}