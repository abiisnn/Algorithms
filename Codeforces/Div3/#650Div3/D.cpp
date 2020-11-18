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

void solve() {
	string s;
	int m;
	cin >> s >> m;
	vector<int> b(m), bucket(27, 0);
	queue<int> zeros;
	
	fore(i, 0, m) cin >> b[i];
	fore(i, 0, s.size()) bucket[s[i] - 'a']++; // creando cubeta

	string ans(m, ' ');
	int pointer = bucket.size() - 1;
	
	while(1) {
		fore(i, 0, m) if(!b[i]) zeros.push(i);
		
		if(!zeros.size()) break;
		while(bucket[pointer] < zeros.size()) {pointer--;}
		
		while(!zeros.empty()) {
			int pos = zeros.front();
			ans[pos] = char(pointer + 'a');
			b[pos] = -1;
			fore(j, 0, m) {
				if(b[j] != -1) b[j] -= abs(pos - j);
			}
			zeros.pop();
		}
		pointer--;
	}
	cout << ans << endl;
}
int main() {
	optimizar_io
	int q; cin >> q;
	while(q--) {
		solve();
	}
}