// https://codeforces.com/problemset/problem/1033/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 1005
int n, ax, ay, bx, by, cx, cy;	
int grid[MAX][MAX];
int visited[MAX][MAX];
vector<pair<int, int>> moves;
void initializeMoves() {
	moves.pb(mp(0, 1));
	moves.pb(mp(0, -1));
	moves.pb(mp(1, 0));
	moves.pb(mp(-1, 0));
	moves.pb(mp(1, 1));
	moves.pb(mp(-1, -1));
	moves.pb(mp(1, -1));
	moves.pb(mp(-1, 1));	
}
// dfs        FROM ---------- TO 
bool dfs(int bx, int by, int cx, int cy) {
	if((bx <= 0) or (by <= 0)) return false;
	if((bx > n) or (by > n)) return false;
	if((bx == cx) && (by == cy)) return true;
	if(visited[bx][by]) return false;
	visited[bx][by] = 1;	
	if(grid[bx][by] == 0) return false;
	for(int i = 0; i < moves.size(); i++) {
		bool flag = dfs(moves[i].first + bx, moves[i].second + by, cx, cy);
		if(flag) return true;
	}
	return false;
}

void printMatrix() {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) 
			cout << grid[i][j] << " ";
		cout << endl;
	}
}
void initializeGrid() {
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			visited[i][j] = 0;
			grid[i][j] = 0;
		}
 	}
 	for(int i = 1; i <= n; i++) {
 		for(int j = 1; j <= n; j++) 
 			grid[i][j] = 1;
 	}
	// Quéen
	grid[ax][ay] = 0;
	int auxX, auxY;
	auxX = ax, auxY = ay;
	for(int i = 0; i <= n; i++) grid[auxX][i] = 0;
	for(int i = n; i > 0; i--) grid[i][auxY] = 0;
	
	auxX = ax, auxY = ay;
	while((auxX > 0) && (auxY <= n)) {
		grid[auxX--][auxY++] = 0;
	}
	auxX = ax, auxY = ay;
	while((auxY > 0) && (auxX <= n)) {
		grid[auxX++][auxY--] = 0;
	}
	auxX = ax, auxY = ay;
	while((auxX <= n) && (auxY <= n)) {
		grid[auxX++][auxY++] = 0;
	}
	auxX = ax, auxY = ay;
	while((auxX > 0) && (auxY > 0)) {
		grid[auxX--][auxY--] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
	// Visited

 	initializeGrid();
 	initializeMoves();
 	// Bob --- Place
	if(dfs(bx, by, cx, cy)) cout << "YES" << endl;
	else cout << "NO" << endl;
}