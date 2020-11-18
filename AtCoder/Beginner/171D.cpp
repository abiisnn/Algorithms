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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	lli b, c; 
	vector<lli> v(n);
	vector<int> bucket(MAX);
	fore(i, 0, n) {
		cin >> v[i];
		bucket[v[i]]++;
	}
	lli sumTotal = 0;
	fore(i, 0, bucket.size()) sumTotal += (bucket[i] * i);
	
	int q; cin >> q;
	fore(i, 0, q) {
		cin >> b >> c;
		sumTotal -= (b * bucket[b]);
		sumTotal -= (c * bucket[c]);
		bucket[c] += bucket[b];
		bucket[b] = 0;
		sumTotal += (bucket[c] * c);
		cout << sumTotal << endl;
	}
}