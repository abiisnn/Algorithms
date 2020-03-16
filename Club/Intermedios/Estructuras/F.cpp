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

void update(vector<set<int>> &m, char toUpdate, int i, char newChar) {
	m[toUpdate - 'a'].erase(i);
	m[newChar - 'a'].insert(i);
}
int query(vector<set<int>> &m,int l, int r) {
	int ans = 0;
	for(auto &i: m) {
		auto it = i.lower_bound(l);
		if(i.end() != it) {
			int num = *(it);
			if((num >= l) && (num <= r) && (i.size() > 0)) {
				ans++;
			}	
		}
	}
	return ans;
}

int main() {
	optimizar_io
	string s;
	int q, kind, l, r, index;
	char c;

	cin >> s >> q;
	vector<set<int>> pos(26);

	for(int i = 0; i < s.size(); i++) {
		pos[s[i] - 'a'].insert(i);
	}
	while(q--) {
		cin >> kind;
		if(kind == 1) {
			cin >> index >> c;
			update(pos, s[index-1], index-1, c);
			s[index -1] = c;
		} else {
			cin >> l >> r;
			cout << query(pos, l-1, r-1) << endl;
		}
	}
}