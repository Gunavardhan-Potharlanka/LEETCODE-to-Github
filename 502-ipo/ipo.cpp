class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> pc;
        for(int i=0;i<profits.size();i++) pc.push_back({capital[i], profits[i]});
        priority_queue<int> pq;
        sort(pc.begin(), pc.end());
        int i=0;
        while(k){
            while(i<pc.size() && pc[i][0]<=w) {pq.push(pc[i][1]); i++;}
            if(pq.empty()) return w;
            w+=pq.top();
            k--;
            pq.pop();
        }
        return w;
    }
};