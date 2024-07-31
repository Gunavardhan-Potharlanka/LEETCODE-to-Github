class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ind = 0, m = matrix.size(), n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        if(target == matrix[0][0] ||target == matrix[m - 1][n - 1]) return true;
        while(target > matrix[ind][n - 1]) ind++;
        auto idx = find(matrix[ind].begin(), matrix[ind].end(), target);
        if(idx == matrix[ind].end()) return false;
        return true;
    }
};