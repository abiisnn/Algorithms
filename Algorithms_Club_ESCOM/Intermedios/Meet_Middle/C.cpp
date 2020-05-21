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
#define MAX 10000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
void printBits(int n) {
	for (int i = sizeof(n) * 8 - 1; ~i; i--)
		cout << ((n >> i) & 1);
	cout << endl;
}
int main() {
	optimizar_io
	int mask =(1 << 4)-1;
	fore(i, 0, 4) {
		printBits(mask);
		mask >>= 1;
		cout << mask << endl;
	}
}