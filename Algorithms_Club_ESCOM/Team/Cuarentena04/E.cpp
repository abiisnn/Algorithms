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
	int n; cin >> n;
	vector<lli> v(n);
	fore(i, 0, n) cin >> v[i];
	sort(v.begin(), v.end());
	bool flag = true;
	do {
		lli sum = 0;
		fore(i, 0, n) {
			sum += v[i];
			if(sum >= 0 && sum <= 99999999) continue;
			flag = false;
			break;
		}
		if(flag) {
			fore(i, 0, n) cout << v[i] << endl;
			return 0;
		}
		flag = true;
	} while ( std::next_permutation(v.begin(), v.end()));
	cout << "Error" << endl;
}