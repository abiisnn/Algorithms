// https://codeforces.com/problemset/problem/339/A
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
	vector<char> a;
	string s; 
	int i;
	cin >> s;
	fore(i, 0, s.size()) {
		if(s[i] != '+') a.pb(s[i]);
	}
	sort(a.begin(), a.end());
	fore(i, 0, a.size() - 1) {
		cout << a[i] << "+";
	}
	cout << a[a.size() - 1] << endl;
}