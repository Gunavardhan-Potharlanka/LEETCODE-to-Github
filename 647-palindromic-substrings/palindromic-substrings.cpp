class Solution {
    bool ispali(string s){
        int n=s.size();
        for(int i=0;i<(n/2)+1;i++) if(s[i]!=s[n-i-1]) return false;
        return true;
    }
public:
    int countSubstrings(string s) {
        int n=s.size(), c=0;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=i;j<n;j++){
                str+=s[j];
                c+=ispali(str);
            }
        }
        return c;
    }
};