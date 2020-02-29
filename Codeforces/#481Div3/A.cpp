#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	optimizar_io
	int n;

	cin >> n;
	vector<int> a(n, 0);
	fore(i, 0, n) cin >> a[i];
	
	set<int> se;
	vector<int> ans;
	for(int i = n-1; i >= 0; i--) {
		if(!se.count(a[i])) {
			ans.pb(a[i]);
		}
		se.insert(a[i]);
	}
	cout << ans.size() << endl;
	for(int i = ans.size()-1; i >= 0; i--) 
		cout << ans[i] << " ";
	cout << endl;
}