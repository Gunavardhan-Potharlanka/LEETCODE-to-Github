class Solution {
    public int largestPerimeter(int[] nums) {
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0 ; i < nums.length ; i++) q.add(nums[i]);
        int a = q.poll();
        int b = q.poll();
        int c = q.poll();
        while(a >= (b + c) && !q.isEmpty()) {
            a = b;
            b = c;
            c = q.poll();
        }
        if(a >= (b + c)) return 0;
        return (a + b + c);
    }
}