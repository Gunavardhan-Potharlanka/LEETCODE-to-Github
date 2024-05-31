class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2) return nums;
        unordered_map<int, int> mp;
        for(int i:nums) mp[i]=mp[i]^i;
        vector<int> v;
        for(auto i:mp) if(i.second) v.push_back(i.second);
        if(v.size()==1) v.push_back(0);
        return v;
    }
};