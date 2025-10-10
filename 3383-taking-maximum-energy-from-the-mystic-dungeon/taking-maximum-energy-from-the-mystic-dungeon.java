class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int res = Integer.MIN_VALUE, n = energy.length;
        int[] calc = new int[n];
        for(int i = 0 ; i < n ; i++) {
            if(i > (k - 1)) {
                if(calc[i - k] < 0) calc[i] = energy[i];
                else calc[i] = (calc[i - k] + energy[i]);
            } else calc[i] = energy[i];
            if(i > (n - k - 1)) res = Math.max(res, calc[i]);
        }
        return res;
    }
}