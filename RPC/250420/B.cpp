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

int main() {
	optimizar_io
	lli n;
	cin >> n;
	lli ans, dig = log10(n);
	if(dig == 0) {
		cout << n << endl;
		exit(0);
	}
	lli num = n, lastDig = 0, aux = 10;
	fore(i, 0, dig-1) aux = aux * 10;
	while(num) {
		lastDig = num % 10;
		num /= 10;
	}
	lli a = aux * lastDig;
	lli aux2 = a + aux;
	if(n-a == aux2-n) ans = aux2;
	else if(n-a < aux2-n) ans = a;
	else ans = aux2;
	cout << ans << endl;
}