class Solution {
    bool hasCycle(int start, vector<vector<int>>& graph, vector<int>& visited, vector<int>& dp) {
        if(visited[start]) return true;
        if(dp[start] != -1) return dp[start];
        visited[start] = 1;
        for(int i : graph[start]) if(hasCycle(i, graph, visited, dp)) return dp[start] = true;
        visited[start] = 0;
        return dp[start] = false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0), dp(numCourses, -1);
        vector<vector<int>> graph(numCourses);
        for(vector<int> v : prerequisites) graph[v[0]].push_back(v[1]);
        for(int i = 0 ; i < numCourses ; i++) if(hasCycle(i, graph, visited, dp)) return false;
        return true;
    }
};