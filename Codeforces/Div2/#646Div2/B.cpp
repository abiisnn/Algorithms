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

int min(int a, int b) {
	if(a < b) return a;
	return b;
}
int check(string &s, int a, int b, char A, char B) {
	int moves = 0;
	fore(i, 0, a) {
		if(s[i] == A) moves++;
	}
	fore(i, a, s.size()) {
		if(s[i] == B) moves++;
	}
	return moves;
}
void solve(string &s) {
	int a, b, bestAns = 500;
	fore(i, 0, s.size()) {
		a = i, b = s.size()-i;
		int r1 = check(s, a, b, '1', '0');
		int r2 = check(s, a, b, '0', '1');
		r2 = min(r1, r2);
		if(r2 < bestAns) bestAns = r2;
	}
	cout << bestAns << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	string s;
	while(t--) {
		cin >> s;
		solve(s);
	}
}