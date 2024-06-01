class Solution {
public:
    int scoreOfString(string s) {
        int x=0;
        for(int i=1;i<s.size();i++) x+=(abs(s[i-1]-s[i]));
        return x;
    }
};