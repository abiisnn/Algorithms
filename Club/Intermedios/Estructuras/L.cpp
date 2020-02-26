#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	optimizar_io
	int n, k, l, r;
	bool lcan, rcan;
	cin >> n >> k;
	vector<int> num(n, 0);
	vector<int> ans(n, 0);
	fore(i, 0, n) cin >> num[i];

	lcan = true; rcan = true;
	while(l < r) {
		if(lcan) {

		}
		if(rcan) {

		}
		if(~(lcan && rcan)) {
			
		}
	}

	if(k == 1) cout << "1 1" << endl;
	else if((l < n) && (r < n) && (l >= 0) && (r >= 0)) {
		cout << l + 1 << " " << r + 1<< endl;
	} else cout << "-1 -1" << endl;

}