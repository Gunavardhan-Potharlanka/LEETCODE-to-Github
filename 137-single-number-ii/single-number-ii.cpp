class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0, n=nums.size();
        for(int i=0;i<32;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if((nums[j] & (1<<i))!=0) c++;}
            if((c%3)!=0) result = (result | (1<<i));
        }
        return result;
    }
};