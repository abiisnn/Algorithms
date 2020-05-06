#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAX 1000000002
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n, number;
	lli k;
	cin >> t;

	while(t--) {
		cin >> n >> k;
		map<lli, lli> counterA;
		vector<lli> A;
		vector<lli> B;
		for(int i = 0; i < n; i++) {
			cin >> number;
			counterA[number]++;
		}
		for(int i = 0; i < n; i++) {
			cin >> number;
			counterA[number]--;
		}
		for(auto &i : counterA) {
			if(i.second == 0) continue;
				lli index = i.first;
			if(i.second > 0) {
				A.push_back(index);
			} else {
				B.push_back(index);
			}
		}
		
		bool flag = false;
		
		if((A.size() == 0) && (B.size() == 0)) {
			flag = true;
		} else if((A.size() == 1) or (B.size() == 1)) {
			if((abs(counterA[A[0]]) == 1) && (abs(counterA[B[0]]) == 1)) {
				lli dif = B[0] - A[0];
				if((dif >= (-1 * k)) && (dif <= k)) flag = true;
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}