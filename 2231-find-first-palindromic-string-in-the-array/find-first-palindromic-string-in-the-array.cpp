class Solution {
    bool ispali(string s){
        int n=s.size();
        for(int i=0;i<(n/2)+1;i++) if(s[i]!=s[n-i-1]) return false;
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string s:words) if(ispali(s)) return s;
        return "";
    }
};