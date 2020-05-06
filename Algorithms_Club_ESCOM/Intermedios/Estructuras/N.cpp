// https://codeforces.com/contest/580/problem/B
// https://vjudge.net/contest/353813#problem/N
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

int main() {
	optimizar_io
	int n, l, r, pr, lr;
	lli d, m, s;
	cin >> n >> d;
	vector<pair<lli, lli>> p;
	vector<lli> sum(n, 0);
	set<pair<int, int>> pos;
	fore(i, 0, n) {
		cin >> m >> s;
		p.pb(mk(m, s));
	}
	sort(p.begin(), p.end());
	
	l = 0, r = 0;
	fore(i, 0, n) pos.insert(mk(i, i));
	while((l < n) && (r < n)) {
		pr = p[r].first;
		lr = p[l].first;
		if((pr - lr) < d) r++;
		else {
			pos.insert(mk(l, r - 1));
			l++;
		}
	}	
	if((l < n) && ((r-1) < n)) pos.insert(mk(l, r - 1));
	sum[0] = p[0].second;
	fore(i, 1, n) sum[i] += sum [i - 1] + p[i].second;
	
	m = 0;
	for(auto &i: pos) {
		l = i.first, r = i.second;
		if(l == 0) s = sum[r];
		else s = sum[r] - sum[l - 1];
		if(s > m) m = s;
	}
	cout << m << endl;
}