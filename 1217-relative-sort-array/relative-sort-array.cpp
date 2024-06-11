class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for(int i:arr1) mp[i]++;
        arr1=vector<int>();
        for(int i:arr2) while(mp[i]) {arr1.push_back(i); mp[i]--;}
        int n=arr1.size();
        for(auto it:mp) while(it.second) {arr1.push_back(it.first); it.second--;}
        sort(arr1.begin()+n, arr1.end());
        return arr1;
    }
};