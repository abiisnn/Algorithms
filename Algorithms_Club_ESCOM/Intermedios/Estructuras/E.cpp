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

bool sortBy(const pair<lli, lli> &a, const pair<lli, lli> &b) {
	if(a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	optimizar_io
	int n, k;
	lli t, b;
	cin >> n >> k;
	vector<pair<lli, lli>> p;
	fore(i, 0, n) {
		cin >> t >> b;
		p.pb(mk(t, b));
	}
	sort(p.begin(), p.end(), sortBy);

	for(auto &i: p) {
		cout << i.first << " " << i.second << endl;
	}
}