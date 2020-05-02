// https://codeforces.com/problemset/problem/200/B
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 100002
typedef long long int lli;

vector<int> cri(MAX, 0);
void fill(int n, int limit){
	for(int i = n; i <= limit; i += n) cri[i] = 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> num(4, 0);
	int d, ans; 
	for(int i = 0; i < num.size(); i++) cin >> num[i];
	cin >> d;

	for(int i = 0; i < num.size(); i++) {
		fill(num[i], d);
	}

	// Count
	ans = 0;
	for(int i = 1; i <= d; i++) {
		if(cri[i]) ans++;
	}
	cout << ans << endl;
}