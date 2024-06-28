class Solution {
    
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> sums;
        for(vector<int> it : roads)  {
            sums[it[0]]++;
            sums[it[1]]++;
        }
        long long ans = 0, x = n;
        vector<pair<int, int>> points;
        for(auto it : sums) points.push_back({it.second, it.first});
        sort(points.begin(), points.end());
        for(int i = points.size() - 1 ; i > -1 ; i--) points[i].first = x--;
        sums.clear();
        for(pair<int, int> it : points) sums[it.second]  = it.first;
        for(vector<int> it : roads) ans += sums[it[0]] + sums[it[1]];
        return ans;
    }
};