class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;
        int ans = 0;
        for(int i : nums) {
            int count = 0;
            if(mp[i - 1] == 0) {
                while(mp[i]) {
                    i++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};