class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return 0;
        }
        bool fnd = false;
        while (n && !fnd) {
            fnd = n & 1;
            n >>= 1;
        }

        return n == 0;
    }
};