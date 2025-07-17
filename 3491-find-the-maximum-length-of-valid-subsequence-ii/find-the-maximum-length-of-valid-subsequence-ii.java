// class Solution {
//     public int recursion(int ind, int mod, int modulus, int[] nums, int[][] dp) {
//         if(dp[mod + 1][ind] != -1) return dp[mod + 1][ind];
//         int res = 0;
//         for(int i = ind + 1 ; i < nums.length ; i++) {
//             if(mod == -1 || (nums[ind] + nums[i]) % modulus == mod)
//                 res = Math.max(res, 1 + recursion(i, (nums[ind] + nums[i]) % modulus, modulus, nums, dp));
//         }
//         return dp[mod + 1][ind] = res;
//     }
//     public int maximumLength(int[] nums, int k) {
//         int[][] dp = new int[k + 2][nums.length];
//         for(int i = 0; i < k + 1 ; i++) Arrays.fill(dp[i], -1);
//         int res =  0;
//         for(int i = 0 ; i < nums.length ; i++) 
//             res = Math.max(res, 1 + recursion(i, -1, k, nums, dp));
//         return res;
//     }
// }

class Solution {
    int find(int i,int rem,int k,int[] nums,int[][] dp){
        int ans=1;
        if(i==nums.length)return 1;
        if(dp[rem][i]!=-1)return dp[rem][i];
        for(int j=i+1;j<nums.length;j++){
            if((nums[i]+nums[j])%k==rem)ans=Math.max(ans,1+find(j,rem,k,nums,dp));
        }
        return dp[rem][i]=ans;
    }
    public int maximumLength(int[] nums, int k) {
        int ans=0;
        int[][] dp=new int[k][nums.length];
        for(int i=0;i<k;i++)Arrays.fill(dp[i],-1);
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                ans=Math.max(ans,find(j,(nums[i]+nums[j])%k,k,nums,dp)+1);
            }
        }
        return ans;
    }
}