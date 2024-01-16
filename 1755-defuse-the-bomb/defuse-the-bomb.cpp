class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(!k) return vector<int>(code.size(), 0);
        vector<int> prefixsum={code[0]};
        int s=code[0];
        for(int i=1;i<code.size();i++) s+=code[i], prefixsum.push_back(s);
        vector<int> ans;
        for(int i=0;i<code.size();i++){
            if(k>0){
                if((i+k)<code.size()) ans.push_back(prefixsum[i+k]-prefixsum[i]);
                else ans.push_back(prefixsum[code.size()-1]-prefixsum[i]+prefixsum[(i+k)%code.size()]);
            }
            else{
                if(i==0) ans.push_back(prefixsum[code.size()-1]-prefixsum[code.size()+k-1]);
                else if((i+k)>0) ans.push_back(prefixsum[i-1]-prefixsum[i+k-1]);
                else if(i+k==0) ans.push_back(prefixsum[i-1]);
                else ans.push_back(prefixsum[i-1]+prefixsum[code.size()-1]-prefixsum[code.size()-abs(i+k-1)%code.size()]);
            }
        }
        return ans;
    }
};