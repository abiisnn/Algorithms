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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
set<char> convert(vector<char> a) {
	set<char> aux;
	fore(i, 0, a.size()) aux.insert(a[i]);
	return aux;
}
map<int, set<char>> m;
vector<vector<char>> matrix = {{'0'},
									   {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}, 
									   {'2', '3', '5', '6', '8', '9', '0'}, 
									   {'3', '6', '9'}, 
									   {'4', '5', '6', '7', '8', '9', '0'},
									   {'5', '6', '8', '9', '0'},
									   {'6', '9'},
									   {'7', '8', '9', '0'},
									   {'8', '9', '0'},
									   {'9'}};
bool canBeCreated(int n) {
	string str = to_string(n);
	bool ans = true;
	fore(i, 1, str.size()) {
		if(m[str[i-1]].count(str[i])) continue;
		else {
			ans = false;
			break;
		} 
	}
	return ans;
}
int main() {
	optimizar_io
	int q, n;
	cin >> q;
	fore(i, 0, matrix.size()) {
		m['0' + i] = convert(matrix[i]);
	}
	while(q--) {
		cin >> n;
		vector<pair<int, int>> res;
		fore(i, 0, 900) {
			if(canBeCreated(i)) res.pb(mk(abs(n-i), i));
		}
		sort(res.begin(), res.end());
		cout << res[0].second << endl;
	}

}