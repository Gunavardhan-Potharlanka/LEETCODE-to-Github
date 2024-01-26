#define ll long long
class Solution {
    ll mod = 1e9+7;
    int recursion(int i, int j, int k, int m, int n, vector<vector<vector<int>>>& dp){
        if(i<0 || i>=m || j<0 || j>=n) return 1;
        if(k==0) return 0;
        
        // if(i<0 || i>m-1 || j<0 || j>n-1) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k]%mod;
        int left=recursion(i, j-1, k-1, m, n, dp)%mod;
        int right=recursion(i, j+1, k-1, m, n, dp)%mod;
        int up=recursion(i-1, j, k-1, m, n, dp)%mod;
        int down=recursion(i+1, j, k-1, m, n, dp)%mod;
        return dp[i][j][k]=((left+right)%mod+(up+down)%mod)%mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        // return 0;
        return recursion(startRow, startColumn, maxMove, m, n, dp)%mod;
    }
};