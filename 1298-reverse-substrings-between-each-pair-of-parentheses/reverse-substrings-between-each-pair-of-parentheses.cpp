class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> ind;
        int n = s.size();
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '(') {
                ind.push(i + 1);
            }
            if(s[i] == ')') {
                int index = ind.top(), x = 0;
                ind.pop();
                reverse(s.begin() + index, s.begin() + i);
            }
        }
        string ans = "";
        for(char c : s) if(c != '(' && c != ')') ans += c;
        return ans;
    }
};