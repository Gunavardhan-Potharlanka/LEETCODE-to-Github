class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> t1(n, 0), t2(n, 0);
        for(vector<int> v: trust){
            t1[v[0]-1]++;
            t2[v[1]-1]++;
        }
        for(int i=0;i<n;i++) if(t1[i]==0 && t2[i]==n-1) return i+1;
        return -1;
    }
};