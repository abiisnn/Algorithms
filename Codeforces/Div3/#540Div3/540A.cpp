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
	int t;
	cin >> t;
	lli n, a, b;
	while(t--) {
		cin >> n >> a >> b;
		lli comprarA = n * a;
		lli aux = n / 2;
		lli one = n % 2;
		lli comprarB = (aux * b) + (one * a);
		cout << std::min(comprarA, comprarB) << endl;
	}
}