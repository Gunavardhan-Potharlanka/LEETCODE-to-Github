class Solution {
    int solve(vector<int>& nums) {
        int maxsofar = max(nums[0], nums[1]), max2 = nums[0];
        for(int i = 2 ; i < nums.size() ; i++) {
            nums[i] += max2;
            max2 = maxsofar;
            maxsofar = max(maxsofar, nums[i]);
        }
        return maxsofar;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        if(nums.size() < 3) return max(nums[0], nums[1]);
        vector<int> dp1 = vector<int>(nums.begin(), nums.end() - 1);
        vector<int> dp2 = vector<int>(nums.begin() + 1, nums.end());
        return max(solve(dp1), solve(dp2));
    }
};