#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
#define LIM 2 * 10e9
typedef long long int lli;
typedef long double ld;
typedef pair<lli, lli> plli;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli total = 0;
struct compare { 
    constexpr bool operator()(plli const& a, plli const& b) const noexcept { return a.first > b.first; }
};
priority_queue<plli, vector<plli>, compare> opt; // Fi: distance, Se: pos
set<lli> pos;

void addElement(lli index, lli dis, int &cont) {
	if(!pos.count(index) && index <= LIM && index >= -LIM) {
		total += dis;
		opt.push(mk(dis, index));
		pos.insert(index);
		cont++;
	}
}  
int main() {
	optimizar_io
	int n, m; cin >> n >> m;
	set<lli> tree;
	lli t;
	fore(i, 0, n) {
		cin >> t;
		opt.push(mk(0, t));
		pos.insert(t); tree.insert(t);
	}
	
	int cont = 0;
	while(1) {
		plli a = opt.top(); opt.pop();
		lli l = a.se - 1, r = a.se + 1, dis = a.fi + 1;
		if(cont < m) addElement(l, dis, cont); else break;
		if(cont < m) addElement(r, dis, cont); else break;
	}
	cout << total << endl;
	for(auto &i: pos) {
		if(!tree.count(i)) cout << i << " ";
	}
	cout << endl;	
}