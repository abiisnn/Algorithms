// https://leetcode.com/problems/set-matrix-zeroes/
#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.size() < 0) return;
    
    bool row = false, column = false;
    for(int i = 0; i < matrix.size(); i++) {
    	if(matrix[i][0] == 0) column = true;
    }
    for(int j = 0; j < matrix[0].size(); j++) {
    	if(matrix[0][j] == 0) row = true;
    }
    
    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 1; j < matrix[i].size(); j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // Rows
    for(int i = 1; i < matrix.size(); i++) {
        if(matrix[i][0] == 0) {
            for(int j = 1; j < matrix[i].size(); j++) 
            	matrix[i][j] = 0;
        }
    }
    for(int j = 0; j < matrix[0].size(); j++) {
        if(matrix[0][j] == 0) {
            for(int i = 1; i < matrix.size(); i++)
                matrix[i][j] = 0;
        }
    }
    if(row) {
    	for(int j = 0; j < matrix[0].size(); j++)
    		matrix[0][j] = 0;
    }
    if(column) {
    	for(int i = 0; i < matrix.size(); i++)
    		matrix[i][0] = 0;
    }
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	setZeroes(matrix);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		} cout << endl;
	}
}