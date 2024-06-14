class Solution {
    int recursion(int ind, int end, vector<int>&nums, vector<int>&dp){
        if(ind>end-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=max(nums[ind]+recursion(ind+2, end, nums, dp), recursion(ind+1, end, nums, dp));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+1, -1), dp2(n+1, -1);
        return max(recursion(0, n-1, nums, dp1), recursion(1, n, nums, dp2));
    }
};