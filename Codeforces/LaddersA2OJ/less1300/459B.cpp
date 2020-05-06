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
	optimizar_io
	int n;
	cin >> n;
	vector<lli> v(n);
	map<lli, lli> bucket;
	lli maxN = 0, minN = 10000000000;
	fore(i, 0, n) {
		cin >> v[i];
		bucket[v[i]]++;
		if(v[i] > maxN) maxN = v[i];
		if(v[i] < minN) minN = v[i];
	}
	lli ans;
	if(maxN == minN) ans = (bucket[minN] * (bucket[minN] - 1)) / 2;
	else ans = bucket[maxN] * bucket[minN];
	cout << maxN - minN << " " << ans << endl;
}
