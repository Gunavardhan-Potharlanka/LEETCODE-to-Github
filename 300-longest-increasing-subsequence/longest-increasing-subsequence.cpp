class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> dp(nums.size(), 1);
        int maxsofar = INT_MIN;
        for(int i = 1 ; i < nums.size() ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
                maxsofar = max(maxsofar, dp[i]);
            }
        }
        return maxsofar;
    }
};