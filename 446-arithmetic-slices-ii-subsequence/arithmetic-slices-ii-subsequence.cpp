#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<ll, ll>> mapping(nums.size(), unordered_map<ll, ll>());
        ll res=0;
        for(ll i=1;i<nums.size();i++){
            for(ll j=0;j<i;j++){
                ll diff=1ll*nums[i]-1ll*nums[j];
                if(mapping[j].find(diff)!=mapping[j].end()){
                    if(mapping[j].find(diff)!=mapping[i].end()){
                        res+=mapping[j][diff];
                        mapping[i][diff]+=mapping[j][diff]+(1ll);
                    }
                    else{
                        mapping[i][diff]=(1ll)+mapping[j][diff];
                        res+=mapping[j][diff];
                    }
                }
                else mapping[i][diff]+=1;
            }
        }
        return int(res);
    }
};