class Solution {
public:
    string reverseWords(string s) {
        int i=0, ind;
        string ans = "";
        for(ind=0;ind<s.size();ind++){
            if(s[ind]==' '){
                string cat = s.substr(i, ind-i);
                if(cat!=""){
                    if(ans == "") ans = cat; 
                    else ans = cat+' '+ans;
                }
                i=ind+1;
            }
        }
        string cat = s.substr(i, ind-i);
        if(i>0 && cat!="") ans = cat+' '+ans;
        else ans = cat+ans;
        return ans;
    }
};