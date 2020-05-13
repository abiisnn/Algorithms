#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	int n;
	string str;
	cin >> n;
	cin >> str;

	int cont = 0, ans = 0;
	fore(i, 0, str.size()) {
		if(str[i] == 'x') {
			cont++;
			if(cont >= 3) {
				ans++;
			}
		} else {
			cont = 0;
		}
	}
	cout << ans << endl;
}