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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int check(vector<int> &v, int l, int r, int isLeft) {
	int last, cont = 1;
	if(isLeft) {
		last = v[l];
		fore(i, l+1, r) {
			if(v[i] > last) cont++;
			else break;
			last = v[i];
		}
	} else {
		last = v[r];
		for(int i = r-1; i > l; i--) {
			if(v[i] > last) cont++;
			else break;
			last = v[i];
		}
	}
	return cont;
}
int main() {
	optimizar_io
	int n; cin >> n;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];

	int l = 0, r = n-1, last = -1;
	string ans = "";
	while(l <= r) {
		if(v[l] == v[r] && l != r && v[l] > last) {
			int takeLeft = check(v, l, r, 1);
			int takeRight = check(v, l, r, 0);
			if(takeRight > takeLeft) ans += string(takeRight, 'R');
			else ans += string(takeLeft, 'L');
			break;
		}
		vector<pair<int, char>> pos;
		pos.pb(mk(v[l], 'L'));
		pos.pb(mk(v[r], 'R'));
		sort(pos.begin(), pos.end());
		int index = -1;
		fore(i, 0, 2) {
			if(pos[i].fi > last) {
				index = i;
				break;
			}
		}	
		if(index == -1) break;
		if(pos[index].se == 'L') {
			l++;
			ans += "L";
		} else {
			r--;
			ans += "R";
		}
		last = pos[index].fi;
	}
	cout << ans.size() << endl;
	cout << ans << endl;
}