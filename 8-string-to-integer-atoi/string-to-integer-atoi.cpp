class Solution {
    int ub=2147483647, lb=-2147483648;
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' ') i++;
        long long sign=1, ans=0;
        for(;i<s.size();i++){
            if(s[i]=='-') {
                if(i>0 && (isdigit(s[i-1]) || s[i-1]=='-' || s[i-1]=='+')) return ans*sign;
                else sign=-1;}
            else if(s[i]=='+') {
                if(i>0 && (isdigit(s[i-1]) || s[i-1]=='-' || s[i-1]=='+')) return ans*sign;
                else continue;}
            else if(isdigit(s[i])){
                ans=ans*10+(s[i]-'0');
                if(ans>ub){
                    if(sign==-1) return lb;
                    else return ub;
                }
            }
            else return sign*ans;
        }
        return sign*ans;
    }
};