/*

class ticTacToe
isNextMoveWinner()
pair<int,int> nextMoveWinner() -1,-1

ticTacToe.nextMovePlayer1
ticTacToe.nextMovePlayer2

v
  0 1 2
0 x x o
1 o - o
2 o o x
next Move = o

  0 1 2
0 x o o
1 o o o 
2 o o x

    Questions:
        -> N X N
        -> Return any of the winner move
        -> If there is not a next Move Winner: -1, -1
        -> We have in the class the state
    Solution:
        - All the row have the same value minus 1 
        - All the column have the same value minus 1
        - All the diagonal have the same value minus 1
        
        -> isNextMoveWinner: O(n*n)
            Check all the rows, check all the columns, check the diagonal
        -> nextMoveWinner: O(n*n)
            Check all the rows, check all the columns, check the diagonal
    Solution: O(n)
        Class will have 2 vectors:
        Rows: [{1, 2}, {0, 3}, {}]
        Columns: [{}, {}, {}]      
*/

class ticTacToe {
    vector<vector<char>> board;
    char state; // 
    
    bool isValidMove(int circle, int x) {
        if(state == 'o' && circle == board.size() - 1) return true;
        if(state == 'x' && x == board.size() - 1) return true;
    }
    bool isNextMoveWinner() { // O(n * n)
        // pair: first = 0, second = x
        // rows
        bool isNextMove = false;
        for(int i = 0; i < board.size(); i++) {
            int circle = 0, x = 0;
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 'o') {
                    circle++;
                } else {
                    x++;
                }
            }
            if(isValidMove(circle, x)) {
                isNextMove = true;
                break;
            }
            
        }
        // Columns
        for(int i = 0; i < board.size(); i++) {
            int circle = 0, x = 0;
            for(int j = 0; j < board[i]; j++) {
                if(board[j][i] == 'o') {
                    circle++;
                } else {
                    x++;
                }
            }   
            if(isValidMove(circle, x)) {
                isNextMove = true;
                break;
            }
        }
        // Diagonal
        int times = 0;
        int circle = 0, x = 0;
        while(times < board.size()) {
            if(board[tiems][times] == 'o') {
                circle++;
            } else {
                x++;
            }
            times++;
        }
        if(isValidMove(circle, x)) {
            isNextMove = true;
        }
        return isNextMove;
    }
    pair<int, int> nextMoveWinner() {
        
    }
}

/*

Interviewer: Manuel

Verdict: Undetermined

Problems: 
TicTacToe winner move

Feedback:
[00:00] / Start Interview
[00:19] / Pronunciation basics (club)
[00:53] / Because that (hackathon)
[02:41] / Interested (optatives)
[03:57] / Schemas (cryptography part)
[06:12] / Mention your directors, where are you publishing it
[10:11] / Take care of icpc mentions
[11:36] / Contestants is better (icpc team)
[14:55] / Prepare the question better (most difficult)
[17:28] - Don't underestimate your teammates
[21:48] / 1st problem
[21:56] + Clarifications 
[25:36] + Write solution (try to exemplify more)
[32:15] / Diagonal (isNextMoveWinner)
[33:16] + 1st idea t=O(n*n) s=O(n)
[36:39] + 2nd idea t=O(n) s=O(n)
[38:14] / Start coding
[43:25] + Think aloud, variable names
[43:44] / Module your code
[44:14] / Take advantage of class variables (board size)
[44:36] + Notice the useless steps
[45:59] - Remember the comments that the interviewers made.
[50:50] + Module one function
*/


