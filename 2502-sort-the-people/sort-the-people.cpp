class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> pairs;
        for(int i = 0 ; i < names.size() ; i++) pairs.push_back({heights[i], names[i]});
        sort(pairs.rbegin(), pairs.rend());
        vector<string> ans;
        for(pair<int, string> v : pairs) ans.push_back(v.second);
        return ans;
    }
};