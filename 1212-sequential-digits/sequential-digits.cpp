class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<10;i++){
            int res=0;
            for(int j=i;j<10;j++){
                res=res*10+j;
                if(res>low-1 && res<high+1) ans.push_back(res);}
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};