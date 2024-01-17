class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        set<int> s;
        int c=0;
        for(auto i:m){
            s.insert(i.second);
            c++;
            if(s.size()<c)return false;
        }
        return true;
    }
};