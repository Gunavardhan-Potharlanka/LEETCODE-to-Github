class Solution {
    public boolean reorderedPowerOf2(int n) {
        String num = "" + n;
        char[] arr = num.toCharArray();
        Arrays.sort(arr);
        num = new String(arr);
        int maxm = 1073741824;
        String cur = "" + maxm;
        while(cur.length() > num.length()) {
            maxm /= 2;
            cur = "" + maxm;
        }
        while(cur.length() == num.length()) {
            char[] curArr = cur.toCharArray();
            Arrays.sort(curArr);
            cur = new String(curArr);
            int j = 0;
            while(j < cur.length() && cur.charAt(j) == num.charAt(j)) j++;
            if(j == cur.length()) return true;
            maxm /= 2;
            cur = "" + maxm;
        }
        return false;
    }
}