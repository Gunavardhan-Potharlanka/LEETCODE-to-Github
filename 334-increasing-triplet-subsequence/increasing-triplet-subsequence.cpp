class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int minyet=nums[0], mini=INT_MAX;
        for(int i=0;i<n;i++){
            minyet=min(minyet, nums[i]);
            if(nums[i]>mini && nums[i]>minyet) return true;
            if(nums[i]>minyet) mini=min(mini, nums[i]);
        }
        return false;
    }
};