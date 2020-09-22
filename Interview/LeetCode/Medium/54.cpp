#include<bits/stdc++.h>
using namespace std;

/******************
    Time complexity: O(n * m), Space complexity: O(n * n)
*/
void updateMove(int &move, int &i, int &j, int &right, int &down, int &up, int &left) {
    if(j >= right) {
        up++;
    } else if(i >= down) {
        right--;
    } else if(j < left) {
        down--;
    } else if(i < up) {
        left++;
    }
    move++;
    move %= 4;
}
void addSpiral(vector<vector<int>>& matrix, vector<pair<int, int>> &moves, int &move, int i, int j, int &right, int &down, int &up, int &left, int &cont, int &limit, vector<int> &spiral) {
    if(cont == limit) return;
    if(j < left or i < up or i >= down or j >= right) {
        int auxi = i - moves[move].first;
        int auxj = j - moves[move].second;
        updateMove(move, i, j, right, down, up, left);
        i = auxi;
        j = auxj;
    } else {
        spiral[cont] = matrix[i][j];
        cont++;
    }
    i = i + moves[move].first;
    j = j + moves[move].second;
    addSpiral(matrix, moves, move, i , j, right, down, up, left, cont, limit, spiral);

}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int down = matrix.size(), right = 0, up = 0, left = 0;
    if(down) right = matrix[0].size();
    int move = 0, cont = 0, limit = right * down;

    vector<int> spiral(right*down);
    addSpiral(matrix, moves, move, 0, 0, right, down, up, left, cont, limit, spiral);
    return spiral;
}

// Time: O(n*m) Space: O(1)
vector<int> spiralOrder(vector<vector<int>>& matrix) { // n x m
    int down = matrix.size(), right = 0, up = 0, left = 0;
    if(down) right = matrix[0].size();
    int move = 0, cont = 0, limit = right * down;

    vector<int> spiral(right*down);
    int i = 0, j = 0;
    while(cont < limit) {
        if(!move) {
            for(int k = left; k < right; k++) {
                spiral[cont] = matrix[i][k];
                cont++; 
            }
            up++;
            j = right-1;
        } else if(move == 1) {
            for(int k = up; k < down; k++) {
                spiral[cont] = matrix[k][j];
                cont++; 
            }
            right--;
            i = down-1;
        } else if(move == 2) {
            for(int k = right-1; k >= left; k--) {
                spiral[cont] = matrix[i][k];
                cont++;
            }
            down--;
            j = left;
        } else {
           for(int k = down-1; k >= up; k--) {
                spiral[cont] = matrix[k][j];
               cont++; 
            }
            left++;
            i = up;
        }
        move++;
        move %= 4;
    }
    return spiral;
}
int main() {
    int n, m; cin >> n >>  m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Spiral" << endl;
    vector<int> spiral = spiralOrder(matrix);
    for(int i = 0; i < spiral.size(); i++) {
        cout << spiral[i] << " ";
    } cout << endl;
}