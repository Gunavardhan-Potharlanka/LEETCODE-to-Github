class Solution {
    int binsearch(int st, int end, int target, vector<int> nums){
        while(st<=end){
            int mid=st+(end-st)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) st=mid+1;
            else end=mid-1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), i=0, j=n-1, b1, b2;
        if(n==1){
            if(nums[0]==target) return 0;
            else return -1;}
        while(i<n-1 && j>-1 && nums[i]>nums[j]) {i++;j--;}
        if(i>0 && nums[i]<nums[i-1]){
            b1=0;
            b2=i;
            if(target>=nums[0]) return binsearch(0, b2-1, target, nums);
            else return binsearch(b2, n-1, target, nums);
        }
        else if(j<n-1 && nums[j]>nums[j+1]){
            b1=0;
            b2=j+1;
            if(target>=nums[0]) return binsearch(0, b2-1, target, nums);
            else return binsearch(b2, n-1, target, nums);
        }
        return binsearch(0, n-1, target, nums);
    }
};