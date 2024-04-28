class Solution {
    vector<vector<int>> res;
    void recursion(int ind, vector<int>& cand, int sum, vector<int> cur, int n){
        if(sum==0){
            res.push_back(cur);
            return;
        }
        if(sum<0 || ind>n-1) return;
        for(int i=ind;i<n;i++){
            cur.push_back(cand[i]);
            recursion(i, cand, sum-cand[i], cur, n);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recursion(0, candidates, target, {}, candidates.size());
        return res;
    }
};