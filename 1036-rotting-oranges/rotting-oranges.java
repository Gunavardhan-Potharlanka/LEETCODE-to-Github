class Pair{
    int first, second;
    public Pair(int a, int b) {
        first = a;
        second = b;
    }
}
class Solution {
    int n, m;
    int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public boolean inBounds(int x, int n) {
        if(x < 0 || x > n - 1) return false;
        return true;
    }
    public int orangesRotting(int[][] grid) {
        Queue<Pair> q = new LinkedList<>();
        int res = 0, c = 0;
        n = grid.length;
        m = grid[0].length;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1) c++;
                if(grid[i][j] == 2) q.add(new Pair(i, j));
            }
        }
        if(c == 0) return 0;
        if(q.isEmpty()) return -1;
        while(!q.isEmpty()) {
            int size = q.size();
            while((size--) > 0) {
                Pair p = q.remove();
                int x = p.first, y = p.second;
                for(int k = 0 ; k < 4 ; k++) {
                    int a = directions[k][0] + x, b = directions[k][1] + y;
                    if(inBounds(a, n) && inBounds(b, m) && grid[a][b] == 1) {
                        c--;
                        grid[a][b] = 0;
                        q.add(new Pair(a, b));
                    }
                }
            }
            res++;
        }
        if(c > 0) return -1;
        return res - 1;
    }
}