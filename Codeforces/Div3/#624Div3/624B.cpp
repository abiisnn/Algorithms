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

bool bubbleSort(vector<int> &v, set<pair<int, int>> &pos) { // O(n^2)
	bool ans = true;
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v.size()-1; j++) {			
			if(v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
				if(!pos.count(mk(j+1, j+2))) {
					ans = false;
					break;
				}
			}
		}
	}
	return ans;
}

int main() {
	int t, a, b, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vector<int> v(n);
		fore(i, 0, n) cin >> v[i];
		set<pair<int, int>> pos;
		fore(i, 0, m) {
			cin >> a;
			pos.insert(mk(a, a+1));
			pos.insert(mk(a+1, a));
		}
		if(bubbleSort(v, pos)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}