#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define MAX 100001
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	lli n, k;
	cin >> t;

	while(t--) {
		cin >> n >> k;
		vector<lli> counterA(MAX, 0);
		vector<lli> counterB(MAX, 0);
		vector<lli> A(n, 0);
		vector<lli> B(n, 0);
		for(int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> B[i];
		}

	}
}