#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 1000005
#define AUX 10000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<int> ans(MAX);
int main() {
	optimizar_io
	ans[1] = 1, ans[2] = ans[4] = ans[6] = 3, ans[3] = 2, ans[5] = 4;
	int i = 7, times = 2, current = 4;
	while(i < MAX) {
		fore(j, 0, times) ans[i++] = current;
		ans[i++] = current + 1; ans[i++] = current;
		current++; times++;
	}
	int t; cin >> t;
	while(t--) {
		int num; cin >> num;
		cout << ans[num] << endl;
	}
}