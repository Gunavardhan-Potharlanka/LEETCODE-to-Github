class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=1073741824;i>0 && i>=n;i/=2) if(i==n) return true;
        return false;
    }
};