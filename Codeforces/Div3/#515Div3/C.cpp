#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	int q, ind; cin >> q;
	char c;
	vector<pair<char, int>> pos(MAX, mk('L', 0));
	int l = 0, r = 0;
	while(q--) {
		cin >> c >> ind;
		if(c == 'L') {
			pos[ind].first = c;
			pos[ind].second = l;
			l++;
		} else if(c == 'R') {
			pos[ind].first = c;
			pos[ind].second = r;
			r++;
		} else { // ?
			int left, right;
			if(pos[ind].first == 'L') {
				left = l - pos[ind].second - 1;
				right = pos[ind].second + r;
			} else {
				right = r - pos[ind].second - 1;
				left = pos[ind].second + l;
			} 
			cout << std::min(left, right) << endl;
		}
	}
}