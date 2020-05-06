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
	int n;
	cin >> n;
	vector<lli> num(n, 0);
	fore(i, 0, n) {
		cin >> num[i];
	}
	int cont = 1;
	vector<int> ans;
	fore(i, 1, n) {
		if(num[i] >= num[i-1]) {
			cont++;
		} else {
			ans.pb(cont);
			cont = 1;
		}
	}
	ans.pb(cont);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() -1] << endl;
}
