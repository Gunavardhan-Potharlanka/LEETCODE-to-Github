#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        ll n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(ll i=0;i<n-3;i++){
            for(ll j=i+1;j<n-2;j++){
                ll k=j+1, l=n-1;
                while(k<l){
                    ll summation=(ll)nums[i]+(ll)nums[j]+(ll)nums[k]+(ll)nums[l];
                    if(summation==target) s.insert({nums[i], nums[j], nums[k], nums[l]});
                    if(summation>target) l--;
                    else k++;
                }
            }
        }
        for(auto it:s) ans.push_back(it);
        return ans;
    }
};