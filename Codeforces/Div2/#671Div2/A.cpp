#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
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

void solve() {
	int n; cin >> n;
	string num; cin >> num;
	int razeOdd = 0, breachEven = 0;
	for(int i = 0; i < n; i+=2) {
		if((num[i]-'0') & 1) razeOdd++;
	}
	for(int i = 1; i < n; i+=2) {
		if(!((num[i]-'0') & 1)) breachEven++;
	}
	bool winRaze = true;
	if(((n & 1) && razeOdd < 1) or (!(n & 1) && breachEven > 0)) {
		cout << 2;
	} else cout << 1;
	cout << endl;
}
int main() {
	int t; cin >> t;
	while(t--) solve();
}