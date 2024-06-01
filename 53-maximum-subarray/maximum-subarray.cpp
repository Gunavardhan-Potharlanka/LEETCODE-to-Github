class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN, cur=0, n=nums.size();
        for(int i=0;i<n;i++){
            cur+=nums[i];
            if(cur>sum) sum=cur;
            if(cur<0) cur=0;
        }
        return sum;
    }
};