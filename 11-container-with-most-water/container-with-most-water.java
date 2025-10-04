class Solution {
    public int maxArea(int[] height) {
        int j = height.length - 1, i = 0, area = 0;
        while(i < j) {
            int t = Math.min(height[i], height[j]), dist=j - i;
            area = Math.max(area, dist * t);
            if(height[i] == t) i++;
            else j--;
        }
        return area;
    }
}