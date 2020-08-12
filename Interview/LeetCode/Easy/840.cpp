#include<bits/stdc++.h>
using namespace std;
/*
    Pass for every position and check that is magic square:
    i, j
    i, i+3
    j, j+3
     j
    i0 1 2 3 4
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    i = 0, j = 0
    i = 1, j = 0
    i = 2, j = 0
*/
bool areEquals(vector<int> &v) {
    for(int i = 0; i < int(v.size())-1; i++) {
        if(v[i] != v[i+1]) return false;
    }
    return true;
}
bool isMagicSquare(vector<vector<int>>&grid, int i, int j) {
    vector<int> sum;
    set<int> nums;
    for(int a = i; a < i+3; a++) {
        for(int b = j; b < j+3; b++) {
            nums.insert(grid[a][b]);
        }
    }
    bool from19 = true;
    int ini = 1;
    for(auto &i: nums) {
        if(i != ini) {
            from19 = false;
            break;
        }
        ini++;
    }
    // Rows
    for(int a = i; a < i+3; a++) {
        int sumRow = 0;
        for(int b = j; b < j+3; b++) {
            sumRow += grid[a][b];
        }
        sum.push_back(sumRow);
    }
    // Columns
     for(int a = j; a < j+3; a++) {
        int sumRow = 0;
        for(int b = i; b < i+3; b++) {
            sumRow += grid[b][a];
        }
        sum.push_back(sumRow);
    }
    // Diagonals
    int sumDiag = 0;
    int a = i, b = j;
    for(int k = 0; k < 3; k++) {
        sumDiag += grid[a][b];
        a++; b++;
    }
    sum.push_back(sumDiag);
    sumDiag = 0;
    a = i+2, b = j+2;
    for(int k = 0; k < 3; k++) {
        sumDiag += grid[a][b];
        a--; b--;
    }
    sum.push_back(sumDiag);
    return areEquals(sum) && from19;
}
int numMagicSquaresInside(vector<vector<int>>& grid) {
    int cont = 0;
    for(int i = 0; i < int(grid.size())-2; i++) {
        for(int j = 0; j < int(grid[i].size())-2; j++) {
            if(isMagicSquare(grid, i, j)) {
                cont++;
            }
        }
    }
    return cont;
}
int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	cout << numMagicSquaresInside(v) << endl;
}