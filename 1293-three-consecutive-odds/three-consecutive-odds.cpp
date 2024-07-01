class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int i = 0, j = 0, c = 0;
        for(j = 0 ; j < 3 ; j++) c += arr[j] % 2;
        if(c == 3) return true;
        while(j < arr.size()) {
            c -= arr[i] % 2;
            i++;
            c += arr[j] % 2;
            j++;
            if(c == 3) return true;
        }
        return false;
    }
};