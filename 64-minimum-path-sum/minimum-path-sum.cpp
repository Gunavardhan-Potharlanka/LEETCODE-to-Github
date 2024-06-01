class Solution {
    long long minsum(int i, int j, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i>m-1 || j>n-1) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(minsum(i+1, j, m, n, grid, dp), minsum(i, j+1, m, n, grid, dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return minsum(0, 0, m, n, grid, dp);
    }
};