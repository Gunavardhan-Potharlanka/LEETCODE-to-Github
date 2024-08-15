class Solution {
    long long int fact(int n) {
        if(n < 2) return 1;
        return n * fact(n - 1);
    }
    void recursion(string& ans, int n, int k, string& str) {
        if(n == 1 || k == 1) {
            ans += str;
            str = "";
            return;
        }
        int times = fact(n - 1), time = (k - 1) / times, nextk = k - (times * time);
        ans += str[time];
        str.erase(time, 1);
        recursion(ans, n - 1, nextk, str);
        return;
    }
public:
    string getPermutation(int n, int k) {
        string ans = "", str = "";
        for(int i = 1 ; i < n + 1 ; i++) str += '0' + i;
        recursion(ans, n, k, str);
        return ans;
    }
};