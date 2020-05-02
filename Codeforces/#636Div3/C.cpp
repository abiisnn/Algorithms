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
#define MAX 35
#define MIN -1000000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli check(vector<lli> &num) {
	lli sum = 0;
	int last = 0, minNeg = MIN, maxPos = 0;
	if(num[0] > 0) {
		last = 1;
		maxPos = num[0];
	}
	else minNeg = num[0];
	fore(i, 1, num.size()) {
		if(num[i] < 0 && last) {
			sum += maxPos;
			maxPos = 0;
			if(num[i] > minNeg) minNeg = num[i];
		}
		if(num[i] > 0 && !last) {
			sum += minNeg;
			minNeg = MIN;
			if(num[i] > maxPos) maxPos = num[i];
		}
		if(num[i] < 0 && !last) {
			if(num[i] > minNeg) minNeg = num[i];
		}
		if(num[i] > 0 && last) {
			if(num[i] > maxPos) maxPos = num[i];
		}
		if(num[i] > 0) last = 1;
		else last = 0;
	}
	if(minNeg != MIN) sum += minNeg;
	if(last) sum += maxPos;
	return sum;
}
int main() {
	optimizar_io
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<lli> num(n);
		fore(i, 0, n) cin >> num[i];
		cout << check(num) << endl;
	}
}