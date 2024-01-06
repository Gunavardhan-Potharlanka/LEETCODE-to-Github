class Solution {
    int maxprofit(int ind, int n, vector<vector<int>>&job, vector<int>&start,  vector<int>&dp){
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        // if(job[ind][0]>=endTime){
            int lb=lower_bound(start.begin()+ind, start.end(), job[ind][1])-start.begin();
            return dp[ind]=max(job[ind][2]+maxprofit(lb, n, job, start,  dp), maxprofit(ind+1, n, job, start, dp));
        // }
        // return dp[endTime]=maxprofit(ind+1, endTime, job, start, dp);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> job;
        for(int i=0;i<profit.size();i++) job.push_back({startTime[i], endTime[i], profit[i]});
        sort(job.begin(), job.end());
        sort(startTime.begin(),startTime.end());
        vector<int> dp(endTime.size()+1,-1);
        int n=job.size();
        return maxprofit(0,n,job,startTime,dp);
    }
};