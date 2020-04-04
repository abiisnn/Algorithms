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
	optimizar_io
	int q;
	lli a, b, n, s;
	cin >> q;
	while(q--) {
		cin >> a >> b >> n >> s;
		lli ineed = s / n;
		lli res = s % n;
		bool ans = false;
		if((ineed <= a) && (res <= b)) ans = true;
		else if(ineed > a) {
			res += (ineed - a) * n;
			if(res <= b) ans = true;
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}