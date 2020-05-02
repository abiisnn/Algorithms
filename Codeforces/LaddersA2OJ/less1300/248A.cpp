// https://codeforces.com/problemset/problem/248/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 100002
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, l, r, totalL, totalR;

	cin >> n;
	totalL = 0; totalR = 0;
	for(int i = 0; i < n; i++) {
		cin >> l >> r;
		if(l) totalL++;
		if(r) totalR++;
	}
	cout << min(totalL, n - totalL) + min(totalR, n - totalR) << endl;
}