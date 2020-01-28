// https://codeforces.com/problemset/problem/236/A
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
typedef long long int lli;

int main() {
	map<char, int> bucket;
	string s;
	cin >> s;
	fore(i, 0, s.size()) {
		bucket[s[i]]++;
	}
	if(bucket.size() & 1) cout << "IGNORE HIM!" << endl;
	else cout << "CHAT WITH HER!" << endl;
}