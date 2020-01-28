#include<bits/stdc++.h>

using namespace std;

int mem[300005];
int dp(int index, vector<int> &op, int m) {
	if(index > op.size()-1) return 0;
	if(index == op.size()-1) return op[index];
	if(mem[index] != -1) return mem[index];
	int si = op[index] + dp(index + m, op, m);
	int no = dp(index + 1, op, m);
	return mem[index] = max(si, no);	
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> opponents(n, 0);
	for(int i = 0; i < n; i++) 
		cin >> opponents[i];
	for(int i = 0; i < 300005; i++) 	
		mem[i] = -1;
	cout << dp(m, opponents, m) << endl;
}
