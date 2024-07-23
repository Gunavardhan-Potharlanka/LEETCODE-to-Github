class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;
        vector<vector<int>> pairs;
        for(int i : nums) pairs.push_back({mp[i], i});
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> ans;
        for(vector<int> i : pairs) ans.push_back(i[1]);
        return ans;
    }
};