#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define endl '\n'
#define MAX 5005
typedef long long int lli;

int main() {
	optimizar_io
	int t, ans;
	string str;
	cin >> t;
	while(t--) {
		cin >> str;
		int last = -1;
		int max = 1;
		int ans = 0;
		for(int i = 0; i < str.size(); i++) {
			if(str[i] == 'R') {
				ans = i - last;
				if(ans > max) max = ans;
				last = i;
			}
		}
		ans = str.size() - last;
		if(ans > max) max = ans;
		cout << ans << endl; 
	}
}