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
#define MAX 62
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
vector<lli> pot(MAX, 0);
void printBits(lli n) {
	for (int i = sizeof(n) * 8 - 1; ~i; i--)
		cout << ((n >> i) & 1);
	cout << endl;
}

lli sequence(int n) {
	lli ans = 0;
	lli j = n-1;
	fori(i, 0, n-2) {
		ans += (j * pot[i]);
		j--;
	}
	ans += n;
	return ans;
}
void iniPot() {
	pot[0] = 1ll;
	fore(i, 1, MAX) pot[i] = pot[i-1] * 2ll;
}
int main() {
	optimizar_io
	iniPot();
	int t;
	lli n;
	cin >> t;
	while(t--) {
		cin >> n;
		lli ans = 0;
		for(int i = sizeof(n) * 8 - 1; ~i; i--) {
			if((n>> i) & 1) ans += sequence(i+1);
		}
		cout << ans << endl;
	}
}

/*
1 2 1 3 1 2 1 4 1 2 1 3
1 2 1 5 1 2 1 3 1 2 1 4
1 2 1 3 1 2 1 6

Para 3:
1 - 2
2 - 1
3 - 1

Para 4
1 - 4  => 1 * 4 = 4
2 - 2  => 2 * 2 = 4
3 - 1  => 3 * 1 = 3
4 - 1  => 4 * 1 = 4

Para 5
1 - 8
2 - 4
3 - 2
4 - 1
5 - 1
Para 6
1 - 16
2 - 8
3 - 4
4 - 2
5 - 1
6 - 1
*/
