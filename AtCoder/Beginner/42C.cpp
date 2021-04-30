#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

set<int> canNotUse;
bool check(int n, int original) {
	bool all = true, greater = n >= original;
	while(n) {
		if(canNotUse.count(n % 10)) {
			all = false;
			break;
		}
		n /= 10;
	}
	return all && greater;
}
int main() {
	optimizar_io
	int n, k; cin >> n >> k;

	fore(i, 0, k) {
		int dig; cin >> dig;
		canNotUse.insert(dig); 
	}
	int original = n;
	while(!check(n, original)) n++;
	
	cout << n << endl;
}