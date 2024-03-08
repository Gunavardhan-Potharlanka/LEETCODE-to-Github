class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=INT_MIN, count=0;
        unordered_map<int, int> mp;
        for(int i:nums){mp[i]++;maxi=max(maxi, mp[i]);}
        for(auto i:mp) if(i.second==maxi) count++;
        return count*maxi;
    }
};