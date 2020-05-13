// https://codeforces.com/contest/1296/problem/B
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
	int t;
	lli n, iwon, res, ans;
	cin >> t;
	while(t--) {
		cin >> n;
		ans = 0;
		while(n >= 10) {
			iwon = n / 10;
			res = n % 10;
			n = iwon + res;
			ans += (10 * iwon);
		}
		ans += n;
		cout << ans << endl;
	}
}