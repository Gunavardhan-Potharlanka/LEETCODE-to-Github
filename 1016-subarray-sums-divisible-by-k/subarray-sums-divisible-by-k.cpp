class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> v(k, 0), mp(k, -1);
        int ans=0, sum=0, n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]%k==0) ans++;
            int rem=sum%k;
            if(i>0 && rem==0) ans++;
            if(rem<0) while(rem<0) rem+=k;
            ans+=v[rem];
            if(i>0 && mp[rem]==i-1) ans--;
            mp[rem]=i;
            v[rem]++;
        }
        return ans;
    }
};