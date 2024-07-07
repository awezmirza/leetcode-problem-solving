class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        int emptyBottles = numBottles;

        numBottles = emptyBottles / numExchange;

        int remainingEmpty = emptyBottles % numExchange;

        while (numBottles) {
            ans += numBottles;
            emptyBottles = numBottles + remainingEmpty;
            numBottles = emptyBottles / numExchange;
            remainingEmpty = emptyBottles % numExchange;
        }

        return ans;

    }
};