class Solution {
    int recursion(int ind, int n, vector<vector<int>>& books, int s, vector<int>& dp) {
        if(ind > n - 1) return 0;
        if(dp[ind] != -1) return dp[ind];
        int awail = s, res = INT_MAX, maxheight = INT_MIN;
        for(int i = ind ; i < n && awail >= books[i][0] ; i++) {
            awail -= books[i][0];
            maxheight = max(maxheight, books[i][1]);
            res = min(res, maxheight + recursion(i + 1, n, books, s, dp));
        }
        return dp[ind] = res;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, -1);
        return recursion(0, n, books, shelfWidth, dp);
    }
};