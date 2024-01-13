class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v1(26, 0), v2(26, 0);
        for(int i=0, j=0;i<s.size(), j<t.size();i++, j++) v1[s[i]-97]++, v2[t[j]-97]++;
        int c=0;
        for(int i=0;i<26;i++) if(v2[i]>v1[i]) c+=v2[i]-v1[i];
        return c;
    }
};