class Solution {
    bool ispalin(string s) {
        int n = s.size();
        for(int i = 0 ; i < n / 2 ; i++) if(s[i] != s[n - i - 1]) return false;
        return true;
    }
    void recursion(int ind, int n, string s, vector<string>& cur, vector<vector<string>>& res) {
        if(ind > n - 1) {
            res.push_back(cur);
            return;}
        for(int i = ind ; i < n ; i++) {
            string substring = s.substr(ind, i - ind + 1);
            if(ispalin(substring)) {
                cur.push_back(substring);
                recursion(i + 1, n, s, cur, res);
                cur.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        recursion(0, s.size(), s, cur, res);
        return res;
    }
};