// https://codeforces.com/problemset/problem/948/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 500
int row, col;
char grid[MAX][MAX];
int visited[MAX][MAX];

bool findSheep(int i, int j) {
	if((i < 0) or (j < 0)) return false;
	if((i >= row) or ( j >= col)) return false;
	if(visited[i][j] == 0) return false;
	if(visited[i][j] == 1) return true;
	if(grid[i][j] == 'S') return true;
	if(grid[i][j] == 'D') return false;
	
	visited[i][j] = false;
	if(findSheep(i - 1, j)) visited[i][j] = true;	
	if(findSheep(i, j - 1)) visited[i][j] = true;
	if(findSheep(i, j + 1)) visited[i][j] = true;
	if(findSheep(i + 1, j)) visited[i][j] = true;
	
	return visited[i][j];
}
void printMatrix() {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) 
			cout << grid[i][j];
		cout << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> row >> col;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			visited[i][j] = -1;
		}
 	}
	for(int i = 0; i < row; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++) {
			grid[i][j] = s[j];
			if(s[j] == '.') grid[i][j] = 'D';
		}
	}

	bool flag = false;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(grid[i][j] == 'W') {
				if(findSheep(i, j)) {
					flag = true;
					break;
				}
			}
		}
	}

	if(flag) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		printMatrix();
	}
}