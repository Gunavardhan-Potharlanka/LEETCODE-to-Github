class Solution {
    public static int maxIndex(int[] arr) {
        int ind = 0;
        for(int i = 0 ; i < arr.length ; i++) if(arr[ind] < arr[i]) ind = i;
        return ind;
    }
    public long pickGifts(int[] gifts, int k) {
        for(int i = 0 ; i < k ; i++) {
            int ind = maxIndex(gifts);
            gifts[ind] = (int)Math.sqrt(gifts[ind]);
        }
        long res = 0;
        for(int i : gifts) res += i;
        return res;
    }
}