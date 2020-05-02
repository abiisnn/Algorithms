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
	int n;
	cin >> n;
	vector<lli> nums(n);
	fore(i, 0, n) {
		cin >> nums[i];
	} 
	// lli ans = 0, bestAns = 0;
	// fore(i, 0, n) {
	// 	ans = 0;
	// 	// cout << "--->" << endl;
	// 	for(int j = i; j < n; j++) {
	// 		ans = ans xor nums[j];
	// 		// cout << ans << endl;
	// 		// cout << "best: " << bestAns << endl;
	// 		if(ans > bestAns) bestAns = ans;
	// 	}
	// }
	// cout << bestAns << endl;
	int a, b;
	cin >> a >> b;
	cout << (a xor b) << endl;
}