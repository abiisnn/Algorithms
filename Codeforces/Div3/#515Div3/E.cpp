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
#define MAX 200000
#define MOD 998244353
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> mul(MAX);
void prePro() {
	mul[0] = 1ll;
	for(int i = 1; i < MAX; i++) {
		mul[i] = (mul[i-1] * 2ll) % MOD;
	}
}
int main() {
	prePro();
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	vector<int> acum(MAX);
	vector<bool> isOn(MAX, false);
	
	for(int i = 0, j = MAX - a.size(); i < a.size(); i++, j++) {
		if(a[i] == '1') isOn[j] = true;
	}
	for(int i = 0, j = MAX - b.size(); i < b.size(); i++, j++) {
		if(b[i] == '1') acum[j]++;
	}

	int ones = 0;
	fore(i, 0, MAX) {
		if(acum[i]) ones++;
		acum[i] = ones;
	}
	
	lli ans = 0;
	for(int i = 0, j = MAX-1; i < acum.size(); i++, j--) {
		if(isOn[j]) {
			ans = (ans + ((acum[j] * mul[i]) % MOD) )% MOD;
		}
	}
	cout << ans << endl;
}