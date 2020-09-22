#include<bits/stdc++.h> 
using namespace std;
bool check(vector<vector<char>> &board, vector<pair<int,int>> &moves, int i, int j, string &word, int index) {
    if(index == word.size()) return true;
    if(i < 0 or i >= board.size()) return false;
    if(j < 0 or j >= board[0].size()) return false;
    if(word[index] != board[i][j]) return false;
    char aux = board[i][j];
    board[i][j] = '#';
    for(int k = 0; k < moves.size(); k++) {
        if(check(board, moves, i + moves[k].first, j + moves[k].second, word, index+1)) return true;
    }
    board[i][j] = aux;
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    char initial = word[0];
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    for(int i = 0; i < int(board.size()); i++) {
        for(int j = 0; j < int(board[i].size()); j++) {
            if(board[i][j] == initial && check(board, moves, i, j, word, 0)) {
                return true;
            } 
        }
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m, ' '));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    string s;
    cin >> s;
    cout << exist(board, s) << endl;
}