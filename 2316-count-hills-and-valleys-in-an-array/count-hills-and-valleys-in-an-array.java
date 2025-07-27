class Solution {
    public int countHillValley(int[] nums) {
        int res = 0, ind = 1, n = nums.length;
        while(ind < n) {
            if(nums[ind] > nums[ind - 1]) {
                while(ind < n && nums[ind] >= nums[ind - 1]) ind++;
                if(ind < n) res++;
            }
            else if(nums[ind] < nums[ind - 1]) {
                while(ind < n && nums[ind] <= nums[ind - 1]) ind++;
                if(ind < n) res++;
            }
            else ind++;
        }
        return res;
    }
}