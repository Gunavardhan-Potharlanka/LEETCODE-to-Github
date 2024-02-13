class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            int n=s.size(), flag=1;
            for(int i=0;i<(n/2)+1;i++) if(s[i]!=s[n-i-1]){flag=0; break;}     
            if(flag) return s;
        }
        return "";
    }
};