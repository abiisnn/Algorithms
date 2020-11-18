#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 500005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33
*/
vector<pair<int, int>> snake;
void saveRow(int n, int m, int row, bool leftToRight) {
	if(leftToRight) {
		for(int i = 1; i <= m; i++) snake.pb(mk(row, i));
	} else {
		for(int i = m; i >= 1; i--) snake.pb(mk(row, i));
	}
}
void printPair(pair<int, int> &p) {
	cout << p.first << " "<< p.second << " ";	
}
int main() {
	optimizar_io
	int n, m, k;
	cin >> n >> m >> k;

	int size = n * m;
	int x = 1;
	while(x <= n) {
		if(x & 1) saveRow(n, m, x, true);
		else saveRow(n, m, x, false);
		x++;
	}
	int j = 0;
	for(int i = 0; i < k - 1; i++) {
		cout << 2 << " ";
		printPair(snake[j]);
		printPair(snake[j+1]);
		j += 2;
		cout << endl;
	}
	cout << n * m - (2 *(k - 1)) << " ";
	for(int i = j; i < n*m; i++) {
		printPair(snake[i]);
	}
	cout << endl;
}