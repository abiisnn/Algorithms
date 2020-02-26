#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 1005
bool matrix[1005][1005];
vector<pair<int, int>> moves;

bool check(int X, int Y) {
	bool ans = true;
	int x, y;
	fore(i, 0, 4) {
		x = X + moves[i].first;
		y = Y + moves[i].second;
		cout << x << " " << y << endl;
		if((x >= 0) && (y >= 0) && (x < MAX) && ( y < MAX)) {
			if(!matrix[x][y]) {
				ans = false;
			}	
		} else ans = false;
	}
	return ans;
}
void fillMoves() {
	int x[] = {0, -1, 0, 1};
	int y[] = {1, 0, -1, 0};
	fore(i, 0, 4){
		moves.pb(mk(x[i], y[i]));	
	}
	
}
void fillMatrix() {
	fore(i, 0, MAX) {
		fore(j, 0, MAX) {
			matrix[i][j] = false;
		}
	}
}
int main() {
	int n, x, y, ans;
	cin >> n;
	vector<pair<int, int>> p;
	fillMoves();
	fillMatrix();
	fore(i, 0, n) {
		cin >> x >> y;
		p.pb(mk(x, y));
		matrix[x][y] = true;
	}
	ans = 0;
	for(auto &i: p) {
		cout << "---------> " << i.first << " " << i.second << endl;
		if(check(i.first, i.second)){
			ans++;
		}
	}
	cout << ans << endl;
}