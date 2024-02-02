#define ll long long
class Solution {
public:
    ll minoperations(ll val, ll n, vector<int>& v, vector<ll>& dp){
        if(val==0) return 0;
        if(dp[val]!=-1) return dp[val];
        ll ans=INT_MAX;
        for(ll i=0;i<n;i++) if(v[i]<=val) ans=(min(ans, 1+minoperations(val-v[i], n, v, dp)));
        return dp[val]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<ll> dp(amount+1, -1);
        ll ans=minoperations(amount, coins.size(), coins, dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};