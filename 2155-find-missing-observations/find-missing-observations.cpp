class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0, t = n + rolls.size();
        for(int i : rolls) sum += i;
        int missing_sum = (mean * t) - sum;
        if(missing_sum > n * 6 || missing_sum < n) return {};
        vector<int> v(n, (missing_sum / n));
        for(int i = 0 ; i < (missing_sum % n) ; i++) v[i]++;
        return v;
    }
};