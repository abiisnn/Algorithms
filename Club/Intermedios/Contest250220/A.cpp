#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	optimizar_io
	int t;
	string str;
	cin >> t;

	while(t--) {
		cin >> str;
		bool ans = true;
		fore(i, 0, str.size()-1) {
			if((str[i+1] - str[i]) != 1) {
				if((str[i] == 'z') && (str[i+1] == 'a')) {
					continue;
				}
				ans = false;
				break;
			}
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}