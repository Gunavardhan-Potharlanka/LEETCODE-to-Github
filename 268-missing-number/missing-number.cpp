class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(), c=0;
        for(int i:nums)c+=i;
        return (n*(n+1)/2)-c;
    }
};