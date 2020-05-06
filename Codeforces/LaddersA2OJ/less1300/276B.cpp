#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int minNumberChar(string &s) {
	map<char, int> bucket;
	fore(i, 0, s.size()) bucket[s[i]]++;
	int even = 0;
	for(auto &i: bucket) {
		if(i.se & 1) even++;
	}
	int ans = 0;
	if(even > 1) ans = even - 1;
	return ans;
}

int main() {
	optimizar_io
	string str;
	cin >> str;

	int number = minNumberChar(str);
	if(number & 1) cout << "Second";
	else cout << "First";
	cout << endl;
}