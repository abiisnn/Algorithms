// https://vjudge.net/contest/374597#problem/I
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
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
int block, dif = 0;
int bucket[MAX];

struct query { int l, r, index; };
bool comp(query a, query b) {
	int aux = a.l/block;
	if(aux != b.l/block) return a.l < b.l;
	if(aux & 1) return a.r < b.r;
	return a.r > b.r;
}
void add(int num) {
	int actual = bucket[num];
	if(actual == 0) dif++;
	bucket[num]++;
}
void remove(int num) {
	int actual = bucket[num];
	if(actual == 1) dif--;
	bucket[num]--;
}
void mo(vector<int> &v, vector<query> &que) {
	vector<int> ans(que.size());
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
		ans[que[i].index] = dif;
	}
	fore(i, 0, ans.size()) cout << ans[i] << endl;
}
int main() {
	optimizar_io
	int n; cin >> n;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];

	int l, r, q; cin >> q;
	block = sqrt(n);
	vector<query> que(q);
	fore(i, 0, q) {
		cin >> l >> r;
		que[i] = {l-1, r-1, i};
	}
	sort(que.begin(), que.end(), comp);
	mo(v, que);
}