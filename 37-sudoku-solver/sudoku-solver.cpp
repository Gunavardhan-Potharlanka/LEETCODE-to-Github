class Solution {
    bool empty = true;
    pair<int, int> nextpos(int r, int c, vector<vector<char>>& board) {
        c++;
        if(c > 8) {
            r++;
            c = 0;
        }
        for(int i = r ; i < 9 ; i++)
            for(int j = (i == r) ? c : 0 ; j < 9 ; j++) if(board[i][j] == '.') return {i, j};
        return {9, 9};
    }
    bool block(int r, int c, int n, vector<vector<char>>& board) {
        int str = (r / 3) * 3, stc = (c / 3) * 3;
        for(int i = str ; i - str < 3 ; i++)
            for(int j = stc ; j - stc < 3 ; j++) if(board[i][j] == '0' + n) return false;
        return true;
    }
    bool col(int c, int n, vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++) if(board[i][c] == '0' + n) return false;
        return true;
    }
    bool row(int r, int n, vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++) if(board[r][i] == '0' + n) return false;
        return true;
    }
    bool clear(int r, int c, int i, vector<vector<char>>& board) {
        return row(r, i, board) && col(c, i, board) && block(r, c, i, board);
    }
    void recursion(int r, int c, vector<vector<char>>& board) {
        if(!empty) return;
        for(int i = 1 ; i < 10 ; i++) {
            if(clear(r, c, i, board)) {
                board[r][c] = '0' + i;
                pair<int, int> nextinds = nextpos(r, c, board);
                if(nextinds.first == 9 && nextinds.second == 9) {
                    empty = false;
                    return;
                }
                recursion(nextinds.first, nextinds.second, board);
                if(!empty) return;
                board[r][c] = '.';
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int i = 0, j = -1;
        pair<int, int> nextinds = nextpos(i, j, board);
        if(nextinds.first == 9 && nextinds.second == 9) {
            empty = false;
            return;
        }
        recursion(nextinds.first, nextinds.second, board);
        return;
    }
};