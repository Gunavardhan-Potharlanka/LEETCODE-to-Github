class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> c(nums.size()+1, 0);
        vector<int> ans;
        for(int i:nums){
            if(c[i]){
                ans.push_back(i);
                break;
            }
            else c[i]++;
        }
        ans.push_back((n*(n+1))/2-accumulate(nums.begin(), nums.end(), 0)+ans[0]);
        return ans;
    }
};