class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0) return 1;
        if(n<0) return myPow(1/x,-n);
        if(n&1) return x*myPow(x*x,n>>1);
        return myPow(x*x,n>>1);
    }
};