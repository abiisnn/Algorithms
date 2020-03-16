#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define endl '\n'
#define MAX 5005
typedef long long int lli;

int main() {
	optimizar_io
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		// cout << "---------" << endl;
		map<int, set<int>> m;
		vector<int> num(n, 0);
		for(int i = 0; i < n; i++) {
			cin >> num[i];
			m[num[i]].insert(i);
		}
		bool ans = false;
		for(int i = 0; i < n; i++) {
			m[num[i]].erase(i);
			if(m[num[i]].size() > 0) {
				int a = *(--m[num[i]].end());
				// cout << "last: " << a << endl;	
				if((a - i + 1) >= 3) {
					ans = true;
					break;
				}
			}
		}
		if(ans) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

}