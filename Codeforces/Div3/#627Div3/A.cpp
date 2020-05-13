#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define endl '\n'
#define MAX 100005
typedef long long int lli;

int main() {
	optimizar_io
	int t, n, a, max;

	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> num(n, 0);
		max = 0;
		for(int i = 0; i < n; i++) {
			cin >> num[i];
			if(num[i] > max) {
				max = num[i];
			}
		}
		bool ans = true;
		for(int i = 0; i < n; i++) {
			if(((max - num[i]) & 1)) {
				ans = false;
			}
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}