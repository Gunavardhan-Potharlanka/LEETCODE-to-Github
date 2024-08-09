#define pb push_back
class Solution {
    void recursion(vector<int>& cur, int ind, vector<int>& nums, vector<vector<int>>& res) {
        res.pb(cur);
        for(int i = ind ; i < nums.size() ; i++) {
            if(i != ind && nums[i] == nums[i - 1]) continue;
            cur.pb(nums[i]);
            recursion(cur, i + 1, nums, res);
            cur.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        recursion(cur, 0, nums, res);
        return res;
    }
};