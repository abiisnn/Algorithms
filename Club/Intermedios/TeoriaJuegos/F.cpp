#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	optimizar_io
	int t, n, a, ans;
	cin >> t;
	while(t--) {
		cin >> n;
		ans = 0;
		for(int i = 0; i < n; i++) {
			cin >> a;
			ans = ans xor a;
		}
		if(ans != 0) {
			cout << "First" << endl;
		} else cout << "Second" << endl;
	}
}