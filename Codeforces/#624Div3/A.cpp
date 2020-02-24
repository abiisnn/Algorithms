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
	int t, ans;
	lli a, b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		lli minN = min(a, b);
		lli maxN = max(a, b);
		lli aux = maxN - minN;
		if(aux == 0) ans = 0;
		else if(minN == a) {
		 	if(aux & 1) ans = 1; 
			else ans = 2;
		} else {
			if(aux & 1) ans = 2;
			else ans = 1;
		}
		cout << ans << endl;
	} 
}
