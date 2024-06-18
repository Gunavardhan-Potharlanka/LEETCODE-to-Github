class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> dfpr;
        int n=profit.size();
        for(int i=0;i<n;i++) dfpr.push_back({difficulty[i], profit[i]});
        sort(dfpr.begin(), dfpr.end());
        sort(worker.begin(), worker.end());
        int ans=0, i=0, maxi=0;
        for(int it:worker){
            while(i<n && dfpr[i][0]<=it){
                maxi=max(maxi, dfpr[i][1]);
                i++;    
            }
            ans+=maxi;
        }
        return ans;
    }
};