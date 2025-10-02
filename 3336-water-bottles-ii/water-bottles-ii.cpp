class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = 0, res = 0;
        while(numBottles != 0) {
            res += numBottles;
            empty += numBottles;
            numBottles = 0;
            if(empty >= numExchange) {
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
        }
        return res;
    }
};