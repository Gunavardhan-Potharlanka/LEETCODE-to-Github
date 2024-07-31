class Solution {
    double power(double x, int n) {
        if(n == 0) return (double)1;
        if(n == 1) return x;
        double ans = 1;
        if(n % 2) ans *= x;
        return ans * power(x * x, n / 2);
    }
public:
    double myPow(double x, int n) {
        double pow = power(x, abs(n));
        if(n > -1) return pow;
        return (1 / pow);
    }
};