class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        if(minutes > grumpy.size()-1) return accumulate(customers.begin(), customers.end(), 0);
        int i=0, j=minutes, cursatis=0, n=grumpy.size();
        for(int ind = 0 ; ind < n ; ind++) if(!grumpy[ind]) cursatis += customers[ind];
        int maxsatis=cursatis;
        for(int x = 0 ; x < minutes ; x++) if(grumpy[x]) cursatis += customers[x];
        while(j < n){
            maxsatis = max(maxsatis, cursatis);
            if(grumpy[i]) cursatis -= customers[i];
            i++;
            if(grumpy[j]) cursatis += customers[j];
            j++;
        }
        return max(maxsatis, cursatis);
    }
};