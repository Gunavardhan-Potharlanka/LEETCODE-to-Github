class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3, 0);
        for(int i:nums) v[i]++;
        nums=vector<int>();
        for(int i=0;i<3;i++) while(v[i]) {nums.push_back(i); v[i]--;}
    }
};