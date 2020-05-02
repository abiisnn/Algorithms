// https://codeforces.com/problemset/problem/231/A
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	int n, t, aux, ans;
	cin >> n;
	vector<int> team(3, 0);
	ans = 0;
	fore(i, 0, n) {
		aux = 0;
		fore(j, 0, 3) {
			cin >> t;
			if(t) aux++;
		}
		if(aux >= 2) ans++;
	}
	cout << ans;
}