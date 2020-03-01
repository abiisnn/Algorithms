#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;
int find(vector<lli> &a, lli target) {
	lli l = 0, r = a.size()-1;
	while(l <= r) {
		lli mid = l + (r - l) / 2;
		if(a[mid] == target) 
			return mid;
		if(a[mid] < target) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int main() {
	optimizar_io
	lli n, k, a, b;
	cin >> n >> k;
	map<lli, lli> bucket;
	map<lli, lli> originalAns;	
	vector<lli> r(n, 0);
	vector<lli> rSorted;
	vector<lli> ans(n, 0);
	set<lli> se;
	fore(i, 0, n) {
		cin >> r[i];
		bucket[r[i]]++;
		if(!se.count(r[i])) {
			rSorted.pb(r[i]);
		}
		se.insert(r[i]);
	}
	sort(rSorted.begin(), rSorted.end());

	vector<lli> sumAcum(rSorted.size(), 0);
	sumAcum[0] = 0;
	fore(i, 1, rSorted.size()) {
		sumAcum[i] =  sumAcum[i - 1] + bucket[rSorted[i - 1]]; 
	}

	fore(i, 0, n) {
		ans[i] = sumAcum[find(rSorted, r[i])];
	}
	fore(i, 0, k) {
		cin >> a >> b;		
		if(r[a - 1] > r[b - 1]) {
			ans[a-1]--;
		} else if(r[b-1] > r[a -1]) {
			ans[b-1]--;
		}
	}
	fore(i, 0, n) {
		cout << ans[i] << " ";
	} cout << endl;
}