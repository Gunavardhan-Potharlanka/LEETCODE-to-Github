class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=nums.size()-2;
        while(ind>-1 && nums[ind]>=nums[ind+1]) ind--;
        if(ind==-1) {reverse(nums.begin(), nums.end()); return;}
        int i=nums.size()-1;
        while(i>ind && nums[i]<=nums[ind]) i--;
        if(i>ind) swap(nums[i], nums[ind]);
        reverse(nums.begin()+ind+1, nums.end());
    }
};