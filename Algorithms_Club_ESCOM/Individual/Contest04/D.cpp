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
#define MAX 105
#define MOD 1000000007 
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, k;
	cin >> n >> k;
	vector<lli> v(n);
	lli minNum = 10000000000;
	lli maxNum = -10000000000;
	fore(i, 0, n) {
		cin >> v[i];
		if(v[i] < minNum) minNum = v[i];
		if(v[i] > maxNum) maxNum = v[i];
	}
	if(k == 1) {
		cout << minNum << endl;
	} else if(k == 2) {
		cout << max(v[0], v[n-1]) << endl;
	} else {
		cout << maxNum << endl;
	}
	
}