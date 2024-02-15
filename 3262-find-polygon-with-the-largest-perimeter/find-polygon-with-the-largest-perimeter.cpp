class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans=INT_MIN, sum=nums[0]+nums[1];
        for(int i=2;i<nums.size();i++){
            if(nums[i]<sum) ans=max(ans, sum+nums[i]);
            sum+=nums[i];
        }
        if(ans==INT_MIN) return -1;
        return ans;
    }
};