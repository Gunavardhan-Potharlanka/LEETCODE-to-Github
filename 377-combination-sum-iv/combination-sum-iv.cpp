class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1 ; i < target + 1 ; i++) {
            for(int j : nums) {
                if(((i - j) > -1) && (dp[i] < INT_MAX)) {
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[target];
    }
};