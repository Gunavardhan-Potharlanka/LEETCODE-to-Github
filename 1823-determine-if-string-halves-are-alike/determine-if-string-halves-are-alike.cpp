class Solution {
    bool isvowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
public:
    bool halvesAreAlike(string s) {
        int c1=0, c2=0;
        for(int i=0;i<s.size()/2;i++) c1+=isvowel(s[i]);
        for(int i=s.size()/2;i<s.size();i++) c2+=isvowel(s[i]);
        return c1==c2;
    }
};