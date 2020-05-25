// https://codeforces.com/contest/888/problem/E
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

lli mod(lli a, lli b) { 
	return (b + (a % b)) % b; 
}
// Return index of the first value greater or equal target
int lowerBound(vector<lli> &a, int l, int r, lli target) { // O(log(n)
	int ans = -1;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(a[mid] >= target) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}
void findLow(vector<lli>&dif, lli sum, lli &maxD, lli &greater, lli m) {
	int index = lowerBound(dif, 0, dif.size()-1, m-sum);
	int inicio = index-10, fin = index+10;
	if(index-10 < 0) inicio = 0;
	if(index+10 > dif.size()) fin = dif.size();
	fore(i, inicio, fin) {
		lli auxSum = mod(dif[i] + sum, m);
		if(auxSum > maxD) maxD = auxSum;
	}
	lli auxSum = mod(greater + sum, m);
	if(auxSum > maxD) maxD = auxSum;
}

int main() {
	optimizar_io
	int n; cin >> n;
	lli m; cin >> m;
	vector<lli> v(n);
	fore(i, 0, n) cin >> v[i];

	int len1 = n/2, len2 = n-n/2; 
	lli s, minDif = (1ll<<60);

	// Getting first Part
	vector<lli> dif;
	lli greater = 0;
	fore(mask, 0, (1 << len1)) {
		s = 0;
		fore(bit, 0, len1){
			if(mask & (1<<bit)) s = mod(s + v[bit], m);
		}		 
		if(s > greater) greater = s;
		dif.pb(s);
	}
	sort(dif.begin(), dif.end());
 
 	// Getting second part
	lli maxAns = 0, sum;
	fore(mask, 0, (1 << len2)) {	
		s = 0;
		fore(bit, 0, len2) {
			if(mask & (1 << bit)) s = mod(s + v[len1 + bit], m);
		}
		findLow(dif, s, maxAns, greater, m);
	}
	cout << maxAns << endl;
}