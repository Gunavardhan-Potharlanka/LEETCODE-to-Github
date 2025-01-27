class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] pre, int[][] queries) {
        int[][] table = new int[numCourses][numCourses];
        for(int i = 0 ; i < pre.length ; i++) table[pre[i][1]][pre[i][0]] = 1;
        for(int i = 0 ; i < numCourses ; i++) {
            for(int j = 0 ; j < numCourses ; j++) {
                if(table[i][j] == 1)
                    for(int k = 0 ; k < numCourses ; k++) if(table[k][i] == 1) table[k][j] = 1;
            }
        }
        List<Boolean> res = new ArrayList<>();
        for(int i = 0 ; i < queries.length ; i++) {
            int x = queries[i][0], y = queries[i][1];
            if(table[y][x] == 1) res.add(true);
            else res.add(false);
        }
        return res;
    }
}