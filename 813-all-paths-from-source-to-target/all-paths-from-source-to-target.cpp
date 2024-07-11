class Solution {
    void recursion(int start, int end, vector<int> path, vector<vector<int>>& res, vector<vector<int>>& graph) {
        cout<<start<<" ";
        path.push_back(start);
        if(start == end) {
            res.push_back(path);
            return;
        }
        for(int i = 0 ; i < graph[start].size() ; i++) recursion(graph[start][i], end, path, res, graph);
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        recursion(0, graph.size() - 1, path, res, graph);
        return res;
    }
};