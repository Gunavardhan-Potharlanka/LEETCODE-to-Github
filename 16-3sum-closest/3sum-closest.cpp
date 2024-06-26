class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=0, mini=INT_MAX, n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1, k=n-1;
            while(j<k){
                int summation=nums[i]+nums[j]+nums[k];
                if(summation==target) return target;
                else{
                    int diff=abs(summation-target);
                    if(diff<mini){
                        ans=summation;
                        mini=diff;
                    }
                    if(summation>target) k--;
                    else j++;
                }
            }
        }
        return ans;
    }
};