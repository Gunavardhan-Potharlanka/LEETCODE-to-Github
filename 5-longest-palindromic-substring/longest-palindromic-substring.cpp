class Solution {
public:
    string longestPalindrome(string s) {
        int start=0, end=1, low, high, n=s.size();
        for(int i=0;i<n;i++){
            low=i-1, high=i;
            while(low>-1 && high<n && s[low]==s[high]){
                if(high-low+1>end){
                    start=low;
                    end=high-low+1;
                }
                low--;
                high++;
            }
            low=i-1, high=i+1;
            while(low>-1 && high<n && s[low]==s[high]){
                if(high-low+1>end){
                    start=low;
                    end=high-low+1;
                }
                low--;
                high++;
            }
        }
        return s.substr(start, end);
    }
};