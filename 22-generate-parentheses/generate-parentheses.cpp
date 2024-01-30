class Solution {
    vector<string> ans;
    void recursion(int left, int right, int n, string s){
        if(left==n && right==n){
            ans.push_back(s);
            return;
        }
        if(left<n) recursion(left+1, right, n, s+"(");
        if(left>right) recursion(left, right+1, n, s+")");
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        recursion(0, 0, n, "");
        return ans;
    }
};