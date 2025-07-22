class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int res = -1, ind = 0, low = 0, sum = 0;
        while(ind < nums.length) {
            if(map.getOrDefault(nums[ind], 0) > 0) {
                res = Math.max(res, sum);
                while(low < nums.length && map.get(nums[ind]) > 0) {
                    map.put(nums[low], map.get(nums[low]) - 1);
                    sum -= nums[low];
                    low++;
                }
            }
            map.putIfAbsent(nums[ind], 0);
            map.put(nums[ind], map.get(nums[ind]) + 1);
            sum += nums[ind];
            ind++;
        }
        return Math.max(res, sum);
    }
}