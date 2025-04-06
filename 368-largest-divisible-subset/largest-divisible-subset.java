class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] v = new int[n];
        Arrays.fill(v, 1);
        int[] prev = new int[n];
        Arrays.fill(prev, -1);
        int m = 0;
        List<Integer> res = new ArrayList<>();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(nums[i] % nums[j] == 0 && v[i] < (v[j] + 1)) {
                    v[i] = v[j] + 1;
                    prev[i] = j;
                }
            }
            if(v[m] < v[i]) m = i;
        }
        for(int i = m ; i > - 1 ; i = prev[i]) res.add(nums[i]);
        return res;
    }
}