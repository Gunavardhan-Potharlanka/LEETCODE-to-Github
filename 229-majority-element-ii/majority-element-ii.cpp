class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> v;
        for(int i : nums) mp[i]++;
        for(auto i : mp) if(i.second > (n / 3)) v.push_back(i.first);
        return v;
    }
};