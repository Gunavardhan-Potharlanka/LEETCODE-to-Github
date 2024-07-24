class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        int i = 0, j = 0, n = intervals.size();
        while(j < n - 1) {
            int maxi = intervals[j][1];
            while(j < n - 1 && maxi >= intervals[j + 1][0]) {
                maxi = max(maxi, intervals[j + 1][1]);
                j++;}
            v.push_back({intervals[i][0], max(maxi, intervals[j][1])});
            j++;
            i = j;
        }
        for(;i < n ; i++) v.push_back({intervals[i][0], intervals[i][1]});
        return v;
    }
};