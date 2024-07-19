class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> v;
        for(int i=0;i<matrix.size();i++){
            int t=min_element(matrix[i].begin(), matrix[i].end())-matrix[i].begin();
            int mi=INT_MIN;
            for(int j=0;j<matrix.size();j++) mi=max(mi, matrix[j][t]);
            if(mi==matrix[i][t]) v.push_back(mi);
        }
        return v;
    }
};