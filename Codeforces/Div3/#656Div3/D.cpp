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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int ocurrences(string &s, int l, int r, char c) {
	int cont = 0;
	fore(i, l, r) {
		if(s[i] == c) cont++;
	}
	return cont;
}

int check(string &s, int l, int r, char c) {
	if(r - l == 1) {
		if(s[l] != c) return 1;
		else return 0;
	}
	int mid = (l + r) / 2;
	int op1 = ((r - l) / 2) - ocurrences(s, l, mid, c) + check(s, mid, r, c+1);
	int op2 = ((r - l) / 2) - ocurrences(s, mid, r, c) + check(s, l, mid, c+1);
	return min(op1, op2);
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		cout << check(s, 0, n, 'a') << endl;
	}
}
