class Solution {
public:
    int func(int ind, int sum, vector<int>& nums, int n, vector<int>& v){
        if(ind>n-1) return 0;
        if(ind==n-1) return nums[n-1];
        if(v[ind]!=-1) return v[ind];
        return v[ind]=max(nums[ind]+func(ind+2, sum, nums, n, v), func(ind+1, sum, nums, n, v));
    }
    int rob(vector<int>& nums) {
        vector<int> v(nums.size()+1, -1);
        return func(0, 0, nums, nums.size(), v);
    }
};