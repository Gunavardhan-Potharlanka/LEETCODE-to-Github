class Solution {
    int empty=0;
    bool column(int r, int c, int key, vector<vector<char>>& board){
        for(int i=0;i<9;i++) if(board[i][c]-'0'==key) return false;
        return true;
    }
    bool row(int r, int c, int key, vector<vector<char>>& board){
        for(int i=0;i<9;i++) if(board[r][i]-'0'==key) return false;
        return true;
    }
    bool block(int r, int c, int key, vector<vector<char>>& board){
        int originx=(r/3)*3, originy=(c/3)*3;
        for(int i=originx;i<originx+3;i++){
            for(int j=originy;j<originy+3;j++){
                if(board[i][j]-'0'==key) return false;
            }
        }
        return true;
    }
    bool canput(int i, int j, vector<vector<char>>& board, int key){
        return block(i, j, key, board) && row(i, j, key, board) && column(i, j, key, board);
    }
    void search(int row, int col, vector<vector<char>>& board){
        if(!empty) return;
        for(int i=row;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int key=1;key<10;key++){
                        if(canput(i, j, board, key)){
                            board[i][j]='0'+key;
                            empty--;
                            search(i, j, board);
                            if(!empty) return;
                            board[i][j]='.';
                            empty++;
                        }
                    }
                    if(board[i][j]=='.') return;
                }
            }
        }
        return;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) for(int j=0;j<9;j++) if(board[i][j]=='.') empty++;
        search(0, 0, board);
    }
};