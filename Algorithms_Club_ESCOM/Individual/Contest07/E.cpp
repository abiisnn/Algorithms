// https://codeforces.com/group/PzLcHnJr9l/contest/278730/problem/E
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
int bucket[MAX];
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
struct Query { int l, r, index, x, y; };
bool comp(Query a, Query b) {
	int aux = a.l/block;
	if(aux != b.l/block) return a.l < b.l;
	if(aux & 1) return a.r < b.r;
	return a.r > b.r;
}
void add(int num) {
	if(!bucket[num]) update(num, 1); // Sum k in index
	bucket[num]++;
}
void remove(int num) {
	if(bucket[num] == 1) update(num, -1); // Sum k in index
	bucket[num]--;
}
void mo(vector<int> &v, vector<Query> &que) {
	vector<lli> ans(que.size());
	int L = 0, R = -1, l, r;
	fore(i, 0, que.size()) {
		l = que[i].l, r = que[i].r;
		while(L > l) { // Add left
			L--;
			add(v[L]);
		}
		while(R < r) { // Add right
			R++;
			add(v[R]);
		}
		while(L < l) { // Remove left
			remove(v[L]);
			L++;
		}
		while(R > r) { // Remove right
			remove(v[R]);
			R--;
		}
		total = query(que[i].y);
		if(que[i].x-1 >= 0) total -= query(que[i].x-1);
		ans[que[i].index] = total;
	}
	fore(i, 0, ans.size()) cout << ans[i] << endl;
}
int main() {
	optimizar_io
	int l, r, n, q, x ,y; cin >> n >> q;
	vector<int> v(n);
	vector<Query> que(q);
	fore(i, 0, n) cin >> v[i];

	block = sqrt(n);
	fore(i, 0, q) {
		cin >> l >> r >> x >> y;
		que[i] = {l-1, r-1, i, x, y};
	}
	sort(que.begin(), que.end(), comp);
	mo(v, que);
}