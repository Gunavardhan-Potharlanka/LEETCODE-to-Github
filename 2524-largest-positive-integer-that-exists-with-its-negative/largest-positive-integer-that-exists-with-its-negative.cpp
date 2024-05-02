class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i:nums) mp[i]++;
        sort(nums.begin(), nums.end());
        if(nums[0]>0) return -1;
        for(int i=nums.size()-1;i>-1 && nums[i]>0;i--) if(mp[nums[i]*-1]>0) return nums[i];
        return -1;
    }
};