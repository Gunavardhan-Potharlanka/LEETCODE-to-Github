class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        long m=-1;
        long pref[]=new long[nums.length+1];
        pref[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            pref[i]=nums[i]+pref[i-1];
            if(i>=2 && nums[i]<pref[i-1]) m=Math.max(m,pref[i]);
        }
        return m;
    }
}