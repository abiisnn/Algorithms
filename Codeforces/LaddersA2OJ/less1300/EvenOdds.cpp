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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	lli n, k;
	cin >> n >> k;

	lli lastOdd, ans;
	if(n & 1) lastOdd = (n / 2) + 1;
	else {
		lastOdd = (n / 2); 
		n--;
	}
	if(k <= lastOdd) ans = k + k -1;
	else ans = k - (n - (k - 1));
	
	cout << ans << endl;
}