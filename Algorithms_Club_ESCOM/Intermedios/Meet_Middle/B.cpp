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

// Return index of the first value greater or equal target
int lowerBound(vector<pair<lli, int>> &a, int l, int r, lli target) { // O(log(n)
	int ans = -1;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(a[mid].fi >= target) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}
void findLow(vector<pair<lli, int>>&dif, lli d, lli &res1, lli &res2, lli &minD, int mask) {
	int index = lowerBound(dif, 0, dif.size()-1, -d);
	int inicio = index-10, fin = index+10;
	if(index-10 <0) inicio = 0;
	if(index+10 > dif.size()) fin = dif.size();
	fore(i, inicio, fin) {
		lli element = dif[i].first;
		lli diference = abs(element + d);
		if(diference < minD) {
			minD = diference;
			res1 = dif[i].se;
			res2 = mask;
		}
	}
}
// Convert mask to positions
void saveAns(vector<int> &s, vector<int> &v, int len, int mask, int n) {
	fore(bit, 0, len){
		if(mask & (1 << bit)) s.pb(n + bit + 1);
		else v.pb(n + bit + 1);
	}
}
void printVector(vector<int> &v) {
	cout << v.size() << " ";
	fore(i, 0, v.size()) cout << v[i] << " ";
	cout << endl;
}
int main() {
	optimizar_io
	int N; cin >> N;
	vector<lli> S(N), V(N);
	fore(i, 0, N) cin >> S[i];
	fore(i, 0, N) cin >> V[i];

	int len1 = N/2, len2 = N-N/2; 
	lli minDif = (1ll<<60), s = 0, v = 0;

	// Getting first Part
	vector<pair<lli, int>> dif;
	fore(mask, 0, (1 << len1)) {
		s = 0, v = 0;
		fore(bit, 0, len1){
			if(mask & (1<<bit)) s += S[bit];
			else v += V[bit];
		}		 
		dif.pb(mk(s-v, mask));
	}
	sort(dif.begin(), dif.end());
 
 	// Getting second part
	lli res1, res2, pos;
	fore(mask, 0, (1 << len2)) {	
		s = 0, v = 0;
		fore(bit, 0, len2) {
			if(mask & (1 << bit)) s += S[len1 + bit];
			else v += V[len1 + bit];
		}
		// Find best answer
		findLow(dif, s-v, res1, res2, minDif, mask);
	}
	vector<int> sv, vv;
	saveAns(sv, vv, len1, res1, 0);
	saveAns(sv, vv, len2, res2, len1);
	
	cout << minDif << endl;
	printVector(sv);
	printVector(vv);
}