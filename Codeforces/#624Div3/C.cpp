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
	int t, n, m;
	string s;

	cin >> t;
	while(t--) {
		cin >> n >> m;
		cin >> s;
		vector<int> pos(m, 0);
		vector<int> range(n+2, 0);
		vector<int> alp(26, 0);

		fore(i, 0, m) cin >> pos[i];

		fore(i, 0, m) {
			range[0] += 1;
			range[pos[i]] += -1;
		}
		range[0] += 1;
	
		fore(i, 1, n+2) {
			range[i] = range[i] + range[i - 1];
		} 
		
		fore(i, 0, n) {
			alp[s[i] - 97] += range[i];
		}
		fore(i, 0, alp.size()) {
			cout << alp[i] << " ";
		} cout << endl;
	}
}