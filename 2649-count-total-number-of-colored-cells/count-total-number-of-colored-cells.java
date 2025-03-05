class Solution {
    public long coloredCells(int n) {
        long k = (long)n;
        return (long)(4 * ((k * (k - 1)) / 2)) + 1;
    }
}