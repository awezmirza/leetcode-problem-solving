class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int n = purchaseAmount%10;
        n = n>=5? 10: 0;
        int m = purchaseAmount/10;
        return 100 - ((m*10) + n);
    }
};