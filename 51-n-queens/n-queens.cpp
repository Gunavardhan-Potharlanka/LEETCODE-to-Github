class Solution {
    bool clear(int r, int c, int n, vector<string>& s) {
        for(int i = r - 1 ; i > -1 ; i--) if(s[i][c] == 'Q') return false;
        for(int i = r - 1, j = c - 1 ; i > -1 && j > -1 ; i--, j--) if(s[i][j] == 'Q') return false;
        for(int i = r - 1, j = c + 1 ; i > -1 && j < n ; i--, j++) if(s[i][j] == 'Q') return false;
        return true;
    }
    void recursion(int r, int n, vector<string>& s, vector<vector<string>>& res) {
        if(r > n - 1) return;
        for(int i = 0 ; i < n ; i++) {
            if(clear(r, i, n, s)) {
                s[r][i] = 'Q';
                if(r == n - 1) {
                    res.push_back(s);
                    s[r][i] = '.';
                    return;
                } else {
                    recursion(r + 1, n, s, res);
                    s[r][i] = '.';
                }
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string x = "";
        for(int i = 0 ; i < n ; i++) x += '.';
        vector<string> s(n, x);
        recursion(0, n, s, res);
        return res;
    }
};