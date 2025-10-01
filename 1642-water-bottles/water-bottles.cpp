class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        long long total = numBottles;

        while(numBottles >= numExchange){
            long long x = numBottles/numExchange;
            total += x;
            numBottles = x + (numBottles % numExchange);
        }
        return total;
    }
};