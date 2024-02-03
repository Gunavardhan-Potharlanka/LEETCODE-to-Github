class Solution {
    int recursion(int ind, int k, int n, vector<int>& arr, vector<int>& dp){
        if(ind>n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=0, maxi=INT_MIN;
        for(int i=ind, j=0;i<n && j<k;i++, j++){
            maxi=max(maxi, arr[i]);
            ans=max(ans, (j+1)*maxi+recursion(i+1, k, n, arr, dp));
        }
        return dp[ind]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1, -1);
        return recursion(0, k, n, arr, dp);
    }
};