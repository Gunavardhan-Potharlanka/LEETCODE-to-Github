class Solution {
    vector<vector<int>> dp;
    bool recursion(int turn, int as, int bs, int i, int j, vector<int>& piles){
        if(i==j) return (as>bs);
        if(dp[i][j]!=-1) return dp[i][j];
        if(turn) return dp[i][j]=(recursion(0, as, bs+piles[i], i+1, j, piles)||recursion(0, as, bs+piles[j], i, j-1, piles));
        return dp[i][j]=(recursion(1, as+piles[i], bs, i+1, j, piles) || recursion(1, as+piles[j], bs, i, j-1, piles));
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return (recursion(1, piles[0], 0, 1, piles.size()-1, piles) || recursion(1, piles[piles.size()-1], 0, 0, piles.size()-2, piles));
    }
};