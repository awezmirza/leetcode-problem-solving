class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int n = purchaseAmount%10;
        int m = purchaseAmount/10;
        cout<<"m is: "<<m<<"\n";
        cout<<"n is: "<<n<<"\n";
        if(n>=5){
            n=10;
        }
        else n = 0;
        m = m*10 + n;
        return 100 - m;
    }
};