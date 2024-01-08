class Solution {
public:
    int minOperations(int n) {
        int c=0;
        while((n&(n-1))){
            cout<<n<<"\n";
            int p=ceil(log2(n));
            int r=(1<<p), l=(r>>1);
            if((n-l)>(r-n)) n=r-n;
            else n=n-l;
            c++;
        }
        return ++c;
    }
};