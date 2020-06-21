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
vector<bool> RisUp = {false, false, true, false, false, false, false, false, false, false};
vector<bool> LisUp = {false, false, false, false, true, true, false, false, false, true};
vector<int> R = {2, 2, 1, 2, 2, 1, 1, 2, 2, 2};
vector<int> L = {2, 0, 1, 0, 1, 1, 2, 0, 2, 1};
vector<int> T = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve() {
	string s; cin >> s;
	int i = s[0] - '0', j = s[1] - '0';
	if(s[0] == '1') {
		cout << T[i] + T[j] << endl;
		return;
	}
	int left = T[i] - R[i], right = T[j] - L[j];
	int ans = left + right;

	if(R[i] == 2 && L[j] == 2) ans += 2;
	else if(RisUp[i] && LisUp[j]) ans += 1;
	else if(R[i] == 1 && !RisUp[i] && L[j] == 1 && !LisUp[j]) ans += 1;
	else ans = T[i] + T[j];
	cout << ans << endl;
}

int main() {
	
	int t; cin >> t;
	string s;
	while(t--) {
		solve();
	}
}