#include<bits/stdc++.h>
#define MOD 1000000007
#define TAM 20
typedef long long int lli;
using namespace std;

int main() {
	int t, n, m, read;
	cin >> t >> n >> m;
	vector<vector<pair<int, int>>> grid;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			grid.push_back(make_pair(0, 0));
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> read;
			grid[i][j] = make_pair(read, 0);
		}
	}

	for(int times = 0; times < t; times++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				grid[i][j].second++;
				if(grid[i][j].first == '.') {
					if(grid[i][j].second == 3) {
						grid[i][j].first = '#';  
					}
					grid[i][j].second %= 3;
				}
			}
		}
	}
}