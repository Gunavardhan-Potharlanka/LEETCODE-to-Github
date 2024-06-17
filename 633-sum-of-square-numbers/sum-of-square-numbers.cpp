class Solution {
    bool issqr(int x){
        if(x<0) return false;
        if(x<2) return true;
        int s=sqrt(x);
        if((s*s)==x){
            cout<<s;
            return true;
        }
        return false;
    }
public:
    bool judgeSquareSum(int c) {
        if(c<3) return true;
        long long int k=1, i=1;
        while(i<c){
            i=k*k;
            if(issqr(c-i)) return true;
            k++;
        }
        return false;
    }
};