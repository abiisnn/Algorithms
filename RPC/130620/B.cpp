#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MOD 11092019
#define MAX 100000
typedef long long int lli;

int main() {
	optimizar_io
	int n, k, num;
	cin >> n >> k;
	vector <int> x(n);
	map<int, int> aux;
	fore(i, 0, n) {
		cin >> x[i];
		aux[x[i]]++;
	}

	set<int> is;
	vector<int> ans;
	int last = -1;
	fore(i, 0, n) {
		aux[x[i]]--;
		int ac = aux[x[i]];
		if(is.count(x[i])) continue;
		if(!ac) {
			is.insert(x[i]);
			ans.pb(x[i]);
			last = x[i];
		} else if() {
			
		}
	}
	fore(i, 0, ans.size()) {
		cout << ans[i] << " ";
	}
	return 0;
}