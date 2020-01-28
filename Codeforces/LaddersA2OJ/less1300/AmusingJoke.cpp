//https://codeforces.com/problemset/problem/141/A
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'

int main() {
	map<char, int> bucket;
	string a, b, c;
	cin >> a >> b >> c;
	fore(i, 0, a.size()) bucket[a[i]]++;
	fore(i, 0, b.size()) bucket[b[i]]++;
	fore(i, 0, c.size()) bucket[c[i]]--;

	bool flag = true;
	for(auto &i: bucket) {
		if(i.second != 0) flag = false;
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}