// https://codeforces.com/contest/1106/problem/B
// https://vjudge.net/contest/353813#problem/C
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

lli giveKind(lli &avaible, lli &cost, lli &d, int type, int &pointer) {
	lli total = 0;
	if(avaible >= d) {
		total = d * cost;
		avaible = avaible - d;
		d = 0;
	} else {
		total = avaible * cost;
		d = d - avaible;
		avaible = 0;
	}
	if(avaible == 0) {
		if(type) pointer++;
	}
	return total;
}

bool giveMin(int &pointer, lli &iwant, lli &result, vector<pair<lli, lli>> &costs, vector<lli> &remain) {
	bool flag = true;
	if(pointer >= costs.size()) flag = false;
	else {
		result = giveKind(remain[costs[pointer].second], costs[pointer].first, iwant, 1, pointer);
	}
	return flag;
}

int main() {
	optimizar_io
	int n, m, t, pointer;
	lli ans, aux, d;
	cin >> n >> m;
	vector<lli> remain(n+1, 0), cost(n+1, 0);
	vector<pair<lli, lli>> minCost; // cost, originalPos 
	fori(i, 1, n) cin >> remain[i];
	fori(i, 1, n) {
		cin >> cost[i];
		minCost.pb(mk(cost[i], i));
	}
	sort(minCost.begin(), minCost.end());

	pointer = 0;
	while(m--) {
		cin >> t >> d;
		ans = giveKind(remain[t], cost[t], d, 0, pointer);
		while(d) {
			aux = 0;
			if(giveMin(pointer, d, aux, minCost, remain)) {
				ans += aux;
			} else {
				ans = 0;
				break;
			}
		} 
		cout << ans << endl;
	}
}