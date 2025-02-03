class Solution {
    public static void dfs(int node, HashSet<Integer> visited, ArrayList<ArrayList<Integer>> adj) {
        visited.add(node);
        for(int i : adj.get(node)) if(visited.contains(i) == false) dfs(i, visited, adj);
    }
    public int findCircleNum(int[][] isConnected) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        HashSet<Integer> visited = new HashSet<>();
        int ans = 0;
        for(int i = 0 ; i < isConnected.length ; i++) adj.add(new ArrayList<>());
        for(int i = 0 ; i < isConnected.length ; i++) {
            for(int j = 0; j < isConnected[i].length ; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj.get(i).add(j);
                    adj.get(j).add(i);
                }
            }
        }
        for(int i = 0 ; i < isConnected.length ; i++) {
            if(visited.contains(i) == false) {
                ans++;
                dfs(i, visited, adj);}
        }
        return ans;
    }
}