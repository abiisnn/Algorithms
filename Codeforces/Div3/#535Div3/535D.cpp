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

char choose(string &str, int l, int r) {
	set<char> pos = {'R', 'G', 'B'};
	pos.erase(str[l]);
	if(r != str.size()-1) pos.erase(str[r+1]);
	char c = *(pos.begin());
	return c;
}
int change(string &str, int l, int r) {
	char c = choose(str, l, r);
	for(int i = l+1; i <= r; i += 2) str[i] = c;
	return (r-l+1)/2;
}
int main() {
	int n, l, r, j, moves = 0;
	string str;
	cin >> n >> str;

	for(int i = 0; i < str.size(); i++) {
		l = i, r = i;
		j = i+1;
		while(j < str.size() && str[j] == str[l]) {
			r = j;
			i = j;
			j++;
		}
		moves += change(str, l, r);
	}
	cout << moves << endl;
	cout << str << endl;
}