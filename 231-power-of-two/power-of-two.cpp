class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        if(__builtin_popcount(n) == 1) return true;
        return false;
    }
};