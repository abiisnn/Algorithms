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

void countBits(vector<int> &bucket, lli n) {
	for(int i = sizeof(n) * 8 - 1, j = 0; i >= 0; i--, j++) {
		if((n >> i) & 1) {
			bucket[j]++;
			break;
		}
	}
}
lli countAns(vector<int> &bucket, lli n) {
	int index = 0;
	for(int i = sizeof(n) * 8 - 1, j = 0; i >= 0; i--, j++) {
		if((n >> i) & 1) {
			index = j;
			break;
		}
	}
	return --bucket[index];
}
void solve() {
	int n; cin >> n;
	vector<lli> v(n);
	fore(i, 0, n) cin >> v[i];
	vector<int> bucketBits(sizeof(v[0])*8);
	fore(i, 0, n) countBits(bucketBits, v[i]);
	
	lli total = 0;
	fore(i, 0, n) total += countAns(bucketBits, v[i]);
	
	cout << total << endl;
}
int main() {
	optimizar_io
	int t; cin >> t;
	while(t--) solve();
}