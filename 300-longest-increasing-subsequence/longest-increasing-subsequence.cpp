class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v={nums[0]};
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=v[v.size()-1]) v[(lower_bound(v.begin(), v.end(), nums[i]))-v.begin()]=nums[i];
            else v.push_back(nums[i]);
        }
        return v.size();
    }
};