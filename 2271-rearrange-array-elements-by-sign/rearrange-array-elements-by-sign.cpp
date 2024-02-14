class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, ans;
        for(int i:nums){
            if(i<0) neg.push_back(i);
            else pos.push_back(i);
        }
        for(int i=0;i<(nums.size()/2);i++) {ans.push_back(pos[i]); ans.push_back(neg[i]);}
        return ans;
    }
};