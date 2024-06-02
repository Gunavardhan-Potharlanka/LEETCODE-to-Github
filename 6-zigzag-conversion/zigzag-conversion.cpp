class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans="";
        vector<string> v(numRows, "");
        int d=1, i=0;
        for(char c:s){
            v[i]+=c;
            if(i==numRows-1) d=-1;
            if(i==0) d=1;
            i+=d;
        }
        for(string ss:v) ans+=ss;
        return ans;
    }
};