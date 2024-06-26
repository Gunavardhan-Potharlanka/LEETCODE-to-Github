class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected=heights;
        int ans=0, n=heights.size();
        sort(expected.begin(), expected.end());
        for(int i=0;i<n;i++) ans+=(heights[i]!=expected[i]);
        return ans;
    }
};