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

bool sortby(const int a, const int b) {
	return a < b;
}

int main() {
	optimizar_io
	int m, n, price, sum = 0;
	cin >> n >> m;
	vector<int> v;
	fore(i, 0, n) {
		cin >> price;
		if(price < 0) v.pb(price);
	}
	sort(v.begin(), v.end(), sortby);
	if(m > v.size()) m = v.size();
	
	fore(i, 0, m) sum += v[i];
	cout << sum * -1 << endl;
}