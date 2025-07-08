class Solution {
    int recursion(int ind, int k, int[][] events, int[][] dp) {
        if (k == 0 || ind == events.length) return 0;
        if (dp[ind][k] != -1) return dp[ind][k];
        int nonpick = recursion(ind + 1, k, events, dp);
        int nextInd = findNextEventIndex(events, events[ind][1]);
        int pick = events[ind][2] + recursion(nextInd, k - 1, events, dp);
        return dp[ind][k] = Math.max(pick, nonpick);
    }

    int findNextEventIndex(int[][] events, int endDay) {
        int low = 0, high = events.length - 1;
        int ans = events.length;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (events[mid][0] > endDay) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public int maxValue(int[][] events, int k) {
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));

        int[][] dp = new int[events.length + 1][k + 1];
        for (int[] row : dp) Arrays.fill(row, -1);

        return recursion(0, k, events, dp);
    }
}
