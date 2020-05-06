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
#define MAX -100000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
lli max(lli a, lli b) {
	if(a > b) return a;
	return b;
}
int main() {
	optimizar_io
	int n, m = 100000; 
	cin >> n;
	vector<lli> nums(n), negOdd, posOdd;
	lli sum = 0;
	fore(i, 0, n) {
		cin >> nums[i];
		if(nums[i] < 0 && (nums[i]&1)) negOdd.pb(nums[i]);
		if(nums[i] > 0 && (nums[i]&1)) posOdd.pb(nums[i]);
		if(nums[i] > 0) sum += nums[i];
	}
	sort(negOdd.begin(), negOdd.end());
	sort(posOdd.begin(), posOdd.end());

	lli ans, c = MAX, a = MAX, b = MAX;
	if(sum & 1) c = sum;
	if(!(sum&1) && negOdd.size() > 0) {
		a = max(sum + negOdd[negOdd.size()-1], negOdd[negOdd.size()-1]);
	}
	if(!(sum&1) && posOdd.size() > 0) {
		b = max(sum - posOdd[0], posOdd[posOdd.size()-1]); 
	}
	ans = max(max(a,b), c);
	cout << ans;
}