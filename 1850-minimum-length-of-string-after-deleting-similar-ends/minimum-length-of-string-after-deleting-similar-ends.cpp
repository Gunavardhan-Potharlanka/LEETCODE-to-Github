class Solution {
public:
    int minimumLength(string s) {
        int  i=0, n=s.size(), j=n-1;
        while(i<n && j>-1 && i<j && s[i]==s[j]){
            while(j>-1 && s[j]==s[i]) j--;
            while(i<n && s[i]==s[j+1]) i++;
        }
        return max(0, j-i+1);
    }
};