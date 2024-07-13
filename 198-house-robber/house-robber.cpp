class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        int maxsofar = max(nums[0], nums[1]), max2 = nums[0];
        for(int i = 2 ; i < nums.size() ; i++) {
            nums[i] += max2;
            max2 = maxsofar;
            maxsofar = max(maxsofar, nums[i]);
        }
        return maxsofar;
    }
};