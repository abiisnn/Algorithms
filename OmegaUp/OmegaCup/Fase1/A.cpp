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
	optimizar_io
	int n, l, r, aux;
	cin >> n;
	map<int, int> buc;
	fore(i, 0, n) {
		cin >> aux;
		buc[aux]++;
	}
	cin >> l >> r;
	int ans = 0;
	for(auto &i: buc) {
		if((i.first >= l) && (i.first <= r)) {
			ans += i.second;
		}
	}
	cout << ans << endl;
}