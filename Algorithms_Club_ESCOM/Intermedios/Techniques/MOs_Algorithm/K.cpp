// https://vjudge.net/contest/374597#problem/K
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
int block;
lli total = 0;

void mapping(vector<pair<lli, int>> &v, vector<int> &nv) {
	sort(v.begin(), v.end());
	lli last = -1;
	int j = -1;
	fore(i, 0, v.size()) {
		if(v[i].fi != last) {
			j++;
		}
		nv[v[i].se] = j;
		last = v[i].fi;
	}
}

// BIT
vector<lli> bit(MAX, 0);
lli F(lli a, lli b){ return a + b; }
void update(int i, lli val) { // O(log(MAX))
	for(i++; i < bit.size(); i += i & -i) 
		bit[i] = F(bit[i], val);
}
lli query(int i) { // O(log(MAX))
	lli ans = 0;
	for(i++; i; i -= i & -i) ans = F(ans, bit[i]);
	return ans;
}
// MO
struct Query { int l, r, index; };
bool comp(Query a, Query b) {
	int aux = a.l/block;
	if(aux != b.l/block) return a.l < b.l;
	if(aux & 1) return a.r < b.r;
	return a.r > b.r;
}
void addL(int num) {
	total += query(num-1);
	update(num, 1);
}
void addR(int num) {
	total += (query(MAX) - query(num));
	update(num, 1);
}
void removeL(int num) {
	total -= query(num-1);
	update(num, -1);
}
void removeR(int num) {
	total -= (query(MAX) - query(num));
	update(num, -1);
}

void mo(vector<int> &v, vector<Query> &que) {
	sort(que.begin(), que.end(), comp);
	vector<lli> ans(que.size());
	int L = 0, R = -1, l, r;
	fore(i, 0, que.size()) {
		l = que[i].l, r = que[i].r;
		while(L > l) { // Add left
			L--;
			addL(v[L]);
		}
		while(R < r) { // Add right
			R++;
			addR(v[R]);
		}
		while(L < l) { // Remove left
			removeL(v[L]);
			L++;
		}
		while(R > r) { // Remove right
			removeR(v[R]);
			R--;
		}
		ans[que[i].index] = total;
	}
	fore(i, 0, ans.size()) cout << ans[i] << endl;
}
int main() {
	optimizar_io
	int l, r, n, q; cin >> n;
	lli num;
	vector<pair<lli, int>> v;
	fore(i, 0, n) {
		cin >> num;
		v.pb(mk(num, i));
	}
	vector<int> nv(n);
	mapping(v, nv);
	
	cin >> q;
	vector<Query> que(q);
	block = sqrt(n);
	fore(i, 0, q) {
		cin >> l >> r;
		que[i] = {l-1, r-1, i};
	}
	mo(nv, que);
}