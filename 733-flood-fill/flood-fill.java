class Pair {
    int first, second;
    public Pair(int a, int b) {
        first = a;
        second = b;
    }
}
class Solution {
    int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public boolean inBounds(int x, int n, int y, int m) {
        if(x < 0 || x > n - 1 || y > m - 1 || y < 0) return false;
        return true;
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int n = image.length, m = image[0].length;
        int c = image[sr][sc];
        if(c == color) return image;
        Queue<Pair> q = new LinkedList<>();
        image[sr][sc] = color;
        q.add(new Pair(sr, sc));
        while(!q.isEmpty()) {
            Pair p = q.remove();
            int x = p.first, y = p.second;
            for(int i = 0 ; i < 4 ; i++) {
                int a = directions[i][0] + x, b = directions[i][1] + y;
                if(inBounds(a, n, b, m) && image[a][b] == c) {
                    image[a][b] = color;
                    q.add(new Pair(a, b));
                }
            }
        }
        return image;
    }
}