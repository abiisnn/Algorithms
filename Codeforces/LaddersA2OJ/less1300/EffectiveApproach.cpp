// https://codeforces.com/problemset/problem/227/B
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

map<int, int> pos;
void position(vector<int> &array) {
	for(int i = 0; i < array.size(); i++) {
		pos[array[i]] = i;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q, number;
	lli vania, sasha;
	cin >> n;
	vector<int> array(n, 0);
	for(int i = 0; i < n; i++) cin >> array[i];

	cin >> q;
	position(array);
	vania = 0, sasha = 0;
	while(q--) {
		cin >> number;
		int p = pos[number];
		vania += p + 1;
		sasha += array.size() - p;
	}
	cout << vania << " " << sasha << endl;
}