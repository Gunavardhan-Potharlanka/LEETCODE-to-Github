class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size(), j = 0, c = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        for(int i = 0; i < n && j < m ; i++){
            while(j < m && g[i] > s[j]) j++;
            if(j < m) {c++; j++;}
            else break;
        }
        return c;
    }
};