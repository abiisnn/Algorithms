#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
typedef long long int lli;

int calculateMov(vector<lli> &b, lli diference) {
	int ans = 0;
	lli auxDif, lastExpected = b[1], expected;
	fore(i, 2, b.size()) {
		expected = lastExpected + diference;
		if(abs(expected - b[i]) > 1) return -1;
		if(abs(expected - b[i]) == 1) ans++;
		lastExpected = expected; 
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<lli> b(n, 0);
	fore(i, 0, n) cin >> b[i];

	if(n <= 2) cout << 0 << endl;
	else {
		vector<pair<int, int>> movs = {{0, 0}, {1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, -1}, {-1, 1}};
		lli a1 = b[0], a2 = b[1], dif = 0;
		int minMoves = 100005, moves = 0;
		bool ans = false;
		for(auto &i: movs) {
			b[0] = a1 + i.first, b[1] = a2 + i.second;
			dif = b[1] - b[0];
			moves = calculateMov(b, dif);
			if(moves != -1) {
				if(b[0] != a1) moves++;
				if(b[1] != a2) moves++;	
				if(moves < minMoves)  minMoves = moves;
				ans = true;
			}
		}
		if(ans) cout << minMoves << endl;
		else cout << -1 << endl;
	} 
}