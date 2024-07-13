class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int>  dp(amount + 1, -1);
        for(int i : coins) if(i < amount + 1) dp[i] = 1;
        for(int i = 1 ; i < amount + 1; i++) {
            for(int j : coins) {
                if((i - j) > 0 && dp[i - j] != -1 && j < (amount + 1)) {
                    if(dp[i] == -1) dp[i] = dp[i - j] + 1;
                    else dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }
        return dp[amount];
    }
};