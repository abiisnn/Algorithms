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
#define MAX 200002
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
void deleteElement(multiset<lli> &s, lli element) {
	if(s.size()) s.erase(s.find(element));
}
int main() {
	int n, q, index, to; cin >> n >> q;
	vector<lli> rating(MAX);
	vector<int> below(MAX);
	vector<multiset<lli>> kinder(MAX, multiset<lli>());
	multiset<lli> evenness;

	fori(i, 1, n) {
		cin >> rating[i] >> index;
		below[i] = index;
		kinder[index].insert(rating[i]);
	}
	fore(i, 1, MAX) {
		if(kinder[i].size()) {
			lli evenn = *--kinder[i].end();
			evenness.insert(evenn);
		}
	}
	fore(i, 0, q) {
		cin >> index >> to;
		int kinAct = below[index];
		lli best = *--kinder[kinAct].end();
		deleteElement(evenness, best);
		deleteElement(kinder[kinAct], rating[index]);
		if(kinder[kinAct].size()) {
			best = *--kinder[kinAct].end();
			evenness.insert(best);
		}
		// Update
		below[index] = to;
		if(kinder[to].size()) {
			best = *--kinder[to].end();
			deleteElement(evenness, best);
		}
		kinder[to].insert(rating[index]);
		best = *--kinder[to].end();
		evenness.insert(best);
		cout << *evenness.begin() << endl;
	}
}