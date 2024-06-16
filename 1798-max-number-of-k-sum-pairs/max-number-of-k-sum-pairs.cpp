class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans=0;
        for(int i:nums) mp[i]++;
        for(int i:nums){
            int x=mp[i];
            mp[i]--;
            int y=mp[k-i];
            mp[k-i]--;
            if(x>0 && y>0) ans++;
        }
        return ans;
    }
};