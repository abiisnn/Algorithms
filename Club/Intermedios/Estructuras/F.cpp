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

int pos(char a) {
	return a - 97;
}

int main() {
	string s;
	vector<set<int>> letters;
	int q, kind, l, r, pos;
	char c;
	cin >> s >> q;
	
	set<int> pos;
	fore(i, 97, 123) {
		letters.pb(pos);
	}

	while(q--) {
		cin >> kind;
		if(kind == 1) { // Update
			cin >> pos >> c;
			update(pos, c);
		} else {
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
	}
}