class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        vector<int> mp1(26, 0), mp2(26, 0);
        for(char c:word1) mp1[c-'a']++;
        for(char c:word2){
            if(!mp1[c-'a']) return false;
            else mp2[c-'a']++;
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return mp1==mp2;
    }
};