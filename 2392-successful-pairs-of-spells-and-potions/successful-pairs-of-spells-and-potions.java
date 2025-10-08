class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length, m = potions.length;
        int[] res = new int[n];
        Arrays.sort(potions);
        for(int i = 0 ; i < n ; i++) {
            int st = 0, end = m - 1;
            while(st <= end) {
                int mid = (st + end) / 2;
                long result = Long.valueOf(spells[i]) * Long.valueOf(potions[mid]);
                if(result >= success) end = mid - 1;
                else st = mid + 1;
            }
            res[i] = m - end - 1;
        }
        return res;
    }
}