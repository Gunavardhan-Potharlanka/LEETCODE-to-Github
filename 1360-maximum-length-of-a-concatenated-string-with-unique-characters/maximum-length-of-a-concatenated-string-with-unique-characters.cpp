class Solution {
    bool comp(string s){
        vector<int> v1(26, 0);
        for(char c:s){
            if(v1[c-'a']>0) return false;
            v1[c-'a']++;
        }
        return true;
    }
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size(), m=0;
        for(int i=0;i<(1<<n);i++){
            string s="";
            int j=i, k=0;
            while(j){
                if(j&1) s+=arr[k];
                k++;
                j=(j>>1);
            }
            if(comp(s)) m=(s.size()>m)?s.size():m;
        }
        return m;
    }
};