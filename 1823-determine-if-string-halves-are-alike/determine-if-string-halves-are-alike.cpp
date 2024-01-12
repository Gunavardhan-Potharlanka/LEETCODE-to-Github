class Solution {
    bool isvowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
public:
    bool halvesAreAlike(string s) {
        int c1=0, c2=0;
        for(int i=0, j=s.size()/2;i<s.size()/2, j<s.size();i++, j++) c1+=isvowel(s[i]), c2+=isvowel(s[j]);
        return c1==c2;
    }
};