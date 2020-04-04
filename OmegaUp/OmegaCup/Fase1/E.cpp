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
	optimizar_io
	int n;
	cin >> n;
	if((n >= 540) && (n <= 1520)) {
		vector<int> est = {580, 980, 1190, 1250, 1420};
		int pos = 3;
		fore(i, 0, est.size()) {
			if(n < est[i]) {
				pos = i;
				break;
			}
		}
		bool adelante = true;
		int ans = 0;
		if(pos == 0) {
			ans = est[0] - n;
		} else if(pos == 3) {
			adelante = false;
			ans = n - est[3];
		} else {
			int ade = est[pos] - n;
			int atr = n - est[pos-1];
			if(ade <= atr) {
				ans = ade;
			} else {
				adelante = false;
				ans = atr;
			}
		}
		if(adelante) cout << "adelante ";
		else cout << "atras ";
		cout << ans << endl;
	} else cout << "error" << endl;
}