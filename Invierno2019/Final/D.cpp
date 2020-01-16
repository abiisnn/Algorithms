#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define MAX 9
 
int main() {
	int n, m, k;
	int l, r, d;
	cin >> n >> m >> k;
	vector<lli> original(n+2, 0);
	vector<lli> barrido(m+2, 0);
	vector<lli> result(n+2, 0);
	vector<pair<pair<int, int>,int>> veces;
	
	for(int i = 1; i <= n; i++) {
		cin >> original[i];
	}
	veces.push_back(make_pair(make_pair(0, 0), 0));
	for(int i = 1; i <= m; i++) {
		cin >> l >> r >> d;
		veces.push_back(make_pair(make_pair(l, r), d));
	}
	for(int i = 1; i <= k; i++) {
		cin >> l >> r;
		barrido[l]++;
		barrido[r+1]--;
	}
	for(int i = 2; i <= m ; i++) {
		barrido[i] += barrido[i-1];
	}
	for(int i = 1; i <= veces.size() - 1; i++) {
		lli l = veces[i].first.first;
		lli r = veces[i].first.second;;
		lli d = veces[i].second;
		lli sum = barrido[i] * d;
		result[l] += sum;
		result[r + 1] -= sum;
	}

	for(int i = 2; i <= result.size() -1; i++) {
		result[i] += result[i-1];
	}
	for(int i = 1; i <= n; i++)
		cout << result[i] + original[i] << " ";
	cout << endl;
}