class Solution {
    int recursion(int ind, int total, int n, vector<int>& rv, vector<vector<int>>& dp){
        if(ind>n-1) return total;
        if(total>rv[n-1]) return total;
        if(dp[ind][total]!=-1) return dp[ind][total];
        int left=0, right=recursion(ind+1, total, n, rv, dp);
        if(rv[ind]>total) left=recursion(ind+1, total+rv[ind], n, rv, dp);
        return dp[ind][total]=max(left, right);
    }
public:
    int maxTotalReward(vector<int>& rv) {
        sort(rv.begin(), rv.end());
        // dp;
        vector<vector<int>> dp(rv.size()+1, vector<int>(2001, -1));
        return recursion(0, 0, rv.size(), rv, dp);
    }
};