#include<bits/stdc++.h>
using namespace std;

int mem[1005][1005] = {-1};
int A[1005];
vector<int> res;
int n;

int lis(int ind, int ant) {
	if(ind >= n)  return 0;
	if(mem[ind][ant] != -1) return mem[ind][ant];
	if(A[ind] > ant) {
		int si = 1 + lis(ind + 1, A[ind]);
		int no = lis(ind + 1, ant);
		return mem[ind][ant] = max(si, no);
	}
	return mem[ind][ant] = lis(ind + 1, ant);
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> A[i];
		}
		int res = lis(0, 0);
		cout << res << endl;
	}
}