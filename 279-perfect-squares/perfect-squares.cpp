class Solution {
public:
    int func(int n, vector<int>& v){
        queue<pair<int, int>> q;
        q.push({n, 0});
        unordered_set<int> vis;
        while(!q.empty()){
            int t=q.front().first, lvl=q.front().second;
            if(t==0) return lvl;
            q.pop();
            for(int i:v){
                if((t-i)>=0 && vis.find(t-i)==vis.end()){
                    q.push({t-i, lvl+1});
                    vis.insert(t-i);
                }
            }
        }
        return 0;
    }
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i*i<=n;i++) v.push_back(i*i);
        return func(n, v);
    }
};